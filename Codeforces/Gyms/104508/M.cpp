#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
string s;
int n, Z[4000006];
vector<int> v[4000006];
ll bit[4000006], p[8000006], ip[8000006];

void modify(int pos, ll val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] = (bit[i] + val + mod) % mod;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i; i -= (i & -i))
        ans = (ans + bit[i]) % mod;
    return ans;
}

void z()
{
    for (int i = 1, mx = 0; i < n; i++)
    {
        if (i < Z[mx] + mx)
            Z[i] = min(Z[mx] - i + mx, Z[i - mx]);
        while (Z[i] + i < n && s[i + Z[i]] == s[Z[i]])
            Z[i]++;
        if (Z[i] + i > Z[mx] + mx)
            mx = i;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    reverse(s.begin(), s.end());
    n = s.size();
    z();

    p[0] = ip[0] = 1;
    for (int i = 1; i <= n * 2; i++)
        p[i] = p[i - 1] * 114514 % mod, ip[i] = ip[i - 1] * 137043501 % mod;

    for (int i = 2; i < n; i++)
        v[i].emplace_back(i), v[i + Z[i]].emplace_back(-i);
    ll ans = 0;
    for (int i = 2; i < n; i++)
    {
        int l = min(Z[i], (i - 1) / 2);
        ans += ip[2 * i] * (query(i - 1) - query(i - l - 1) + mod) % mod;
        for (auto j : v[i])
        {
            if (j > 0)
                modify(j, p[j]);
            else
                modify(-j, -p[-j]);
        }
    }
    ans %= mod;
    cout << p[n] * ans % mod << '\n';
}