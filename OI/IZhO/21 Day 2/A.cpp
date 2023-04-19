#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1000000007;

ll n, p[1000006], vis[1000006], ans, fac[1000006], ifac[1000006];
vector<int> v;

int dfs(int i)
{
    if (!vis[p[i]])
    {
        vis[p[i]] = 1;
        return dfs(p[i]) + 1;
    }
    return 0;
}

ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll C(int n, int m)
{
    return (fac[n] * ifac[m] % mod) * ifac[n - m] % mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fac[0] = ifac[0] = 1;
    cin >> n;
    for (int i = 1; i <= n + 5; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = inv(fac[i]);
    }

    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            v.emplace_back(dfs(i));
    for (int k : v)
    {
        ans = (ans + fac[n] * n % mod * k) % mod;
        if (k >= 2)
            ans = (ans - k * fac[n - 2] * 2 % mod * (n * n % mod * (n - 1) % mod * inv(2) % mod - (n - 1) * n % mod * (2 * n - 1) % mod * inv(6) % mod)) % mod;
        if (k % 2 == 0)
            ans = (ans + C(n, k) * fac[n - k] % mod * fac[k / 2] % mod * fac[k / 2] * 2 % mod * (((n - k) * inv(k + 1) + 1) % mod)) % mod;
    }
    cout << (ans + mod) % mod << '\n';
}
