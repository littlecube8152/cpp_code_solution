#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll base = 127, mod = 1234567891, B = 100000;
ll small[B], big[B];

ll basepow(ll p)
{
    p %= mod - 1;
    return small[p % B] * big[p / B] % mod;
}

struct Hash
{
    ll len, val;
};

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

Hash dupe(Hash h, ll cp, ll ip)
{
    // h + h * p + h * p^2 + ... + h * p^c-1 = h * (p^c - 1)/(p - 1)
    if (cp == 0)
        return Hash{0, 0};
    ll m = (basepow(h.len * cp) - 1) * ip % mod;
    return Hash{h.len * cp, h.val * m % mod};
}

Hash concat(Hash f, Hash g)
{
    return Hash{f.len + g.len, (f.val + g.val * basepow(f.len)) % mod};
}

int n, t, r[60];
vector<pll> E[100100];
ll l[100100], ip[100100];
Hash f[100100];
char c[100100];

int build(string s)
{
    s = ' ' + s;
    stack<int> st;
    st.push(++t);
    for (int i = 1; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            ll sz = 0;
            while (i < s.size() && isdigit(s[i]))
                sz = sz * 10 + (s[i++] - '0');
            E[st.top()].emplace_back(pll(++t, sz));
            if (s[i] == '(')
                st.push(t);
            else
                E[t].emplace_back(pii(t + 1, 1)), c[++t] = s[i];
        }
        else if (s[i] == ')')
            st.pop();
        else
            E[st.top()].emplace_back(pii(++t, 1)), c[t] = s[i];
    }
    return st.top();
}

void dfs(int i)
{
    f[i] = Hash{0, 0};
    if (!E[i].size())
        l[i] = 1, f[i] = Hash{1, c[i] - 'A'};
    else
        for (auto [j, w] : E[i])
        {
            dfs(j);
            l[i] += l[j] * w;
            f[i] = concat(f[i], dupe(f[j], w, ip[j]));
        }
    ip[i] = fpow(fpow(base, l[i]) - 1, mod - 2);
}

Hash getHash(int i, ll x)
{
    if (!E[i].size())
        return f[i];
    else
    {
        Hash cur = {0, 0};
        for (auto [j, w] : E[i])
            if (l[j] * w > x)
            {
                cur = concat(cur, dupe(f[j], x / l[j], ip[j]));
                return concat(cur, getHash(j, x % l[j]));
            }
            else
            {
                cur = concat(cur, dupe(f[j], w, ip[j]));
                x -= l[j] * w;
            }
        return cur;
    }
}

char getChar(int i, ll x)
{
    if (!E[i].size() && x == 0)
        return c[i];
    else
    {
        for (auto [j, w] : E[i])
            if (l[j] * w > x)
                return getChar(j, x % l[j]);
            else
                x -= l[j] * w;
    }
    return ' ';
}

signed main()
{
    small[0] = 1;
    for (int i = 1; i < B; i++)
        small[i] = small[i - 1] * base % mod;
    big[0] = 1;
    big[1] = small[B - 1] * base % mod;
    for (int i = 2; i < B; i++)
        big[i] = big[i - 1] * big[1] % mod;

    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        r[i] = build(s);
        dfs(r[i]);
        v.emplace_back(i);
    }
    sort(v.begin(), v.end(), [&](int i, int j)
         { 
            if(i == j)
                return false; 
            ll L = -1, R = 1e11;
            while (L < R)
            {
                ll mid = (L + R + 1) / 2;
                Hash p = getHash(r[i], mid), q = getHash(r[j], mid);
                if (p.len != q.len || p.val != q.val)
                    R = mid - 1;
                else
                    L = mid;
            }
            return make_pair(getChar(r[i], L + 1), i) < make_pair(getChar(r[j], L + 1), j); });
    for (int i = 0; i < n; i++)
        cout << v[i] << '\n';
}
