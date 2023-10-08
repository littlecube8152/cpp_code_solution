/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = MOD2;

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

// find f(x)ᵖ mod xᵐ in O(m|f|)
vector<ll> fpow(vector<ll> f, ll p, ll m)
{
    int b = 0;
    while (b < f.size() && f[b] == 0)
        b++;
    f = vector<ll>(f.begin() + b, f.end());
    int n = f.size();
    f.emplace_back(0);
    vector<ll> q(min(m, b * p), 0);
    q.emplace_back(fpow(f[0], p));
    for (int k = 0; q.size() < m; k++)
    {
        ll res = 0;
        for (int i = 0; i < min(n, k + 1); i++)
            res = (res + p * (i + 1) % mod * f[i + 1] % mod * q[k - i + b * p]) % mod;
        for (int i = 1; i < min(n, k + 1); i++)
            res = (res - f[i] * (k - i + 1) % mod * q[k - i + 1 + b * p]) % mod;
        res = (res < 0 ? res + mod : res) * inv(f[0] * (k + 1) % mod) % mod;
        q.emplace_back(res);
    }
    return q;
}

int n, k;
ll ans = 0;

signed main()
{
    fast;
    cin >> n >> k;
    vector<ll> f(10, 0);
    for (int i = 1; i <= k; i++)
    {
        int d;
        cin >> d;
        f[d] = 1;
    }
    f = fpow(f, n / 2, n * 5);
    for (auto i : f)
        ans = (ans + i * i) % mod;
    cout << ans << '\n';
}
