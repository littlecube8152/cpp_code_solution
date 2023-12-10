#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const ll mod = 1'000'000'007;
using table = array<ll, (1 << 16)>;

table convoution(table p, table q, bool isand)
{
    for (int b = 1; b < (1 << 16); b <<= 1)
        for (int mask = 0; mask < (1 << 16); mask++)
            if (isand ^ ((mask & b) > 0))
                p[mask] = (p[mask] + p[mask ^ b]) % mod,
                q[mask] = (q[mask] + q[mask ^ b]) % mod;

    for (int mask = 0; mask < (1 << 16); mask++)
        p[mask] = p[mask] * q[mask] % mod;

    for (int b = 1; b < (1 << 16); b <<= 1)
        for (int mask = 0; mask < (1 << 16); mask++)
            if (isand ^ ((mask & b) > 0))
                p[mask] = (p[mask] - p[mask ^ b] + mod) % mod;
    return p;
}

table operator+(table a, table b)
{
    for (int mask = 0; mask < (1 << 16); mask++)
        a[mask] = (a[mask] + b[mask]) % mod;
    return a;
}

table no;

bool isop(char c)
{
    return c == '?' || c == '&' || c == '|';
}

int build(int b, bool inv)
{
    int mask = 0;
    for (int i = 0; i < 16; i++)
        if (inv ^ ((i & (1 << b)) > 0))
            mask ^= (1 << i);
    return mask;
}

int var[256];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fill(all(no), 0);
    for (int i = 0; i < 4; i++)
        var['A' + i] = build(i, 0), var['a' + i] = build(i, 1);

    string s;
    cin >> s;

    vector<table> state;
    vector<int> brac, ops;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(')
            brac.emplace_back(i);
        else if (c == ')')
        {
            int j = brac.back();
            if (j && isop(s[j - 1]))
            {
                table a = state.back();
                state.pop_back();
                table b = state.back();
                table c = no;
                if (s[j - 1] == '?' || s[j - 1] == '|')
                    c = c + convoution(a, b, 0);
                if (s[j - 1] == '?' || s[j - 1] == '&')
                    c = c + convoution(a, b, 1);
                state.back() = c;
            }
            brac.pop_back();
        }
        else if (i == 0 || s[i - 1] == '(')
        {
            state.emplace_back(no);
            if (s[i] == '?')
            {
                for (int k = 0; k < 4; k++)
                    state.back()[var['A' + k]] = 1, state.back()[var['a' + k]] = 1;
            }
            else
            {
                state.back() = no;
                state.back()[var[s[i]]] = 1;
            }
        }
    }
    int n;
    cin >> n;
    vector<pii> r;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        r.emplace_back(pii(a + 2 * b + 4 * c + 8 * d, e));
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << 16); mask++)
    {
        bool valid = 1;
        for (auto [b, v] : r)
            if ((mask >> b & 1) != v)
                valid = 0;
        if (valid)
            ans = (ans + state.back()[mask]) % mod;
    }
    cout << ans << '\n';
}