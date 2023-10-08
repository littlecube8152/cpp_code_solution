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

const ll mod = MOD;
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

vector<ll> mul(vector<ll> &f, vector<ll> &g)
{

    int m = (int)(f.size() + g.size()) - 1,
        n = (int)max(f.size(), g.size());
    if (f.size() <= 30 && g.size() <= 30)
    {
        vector<ll> h(m, 0);
        for (int i = 0; i < f.size(); i++)
            for (int j = 0; j < g.size(); j++)
                h[i + j] = (h[i + j] + f[i] * g[j]) % mod;
        return h;
    }

    if (n & 1)
        n++;
    f.resize(n, 0);
    g.resize(n, 0);
    vector<ll> f1 = vector<ll>(f.begin(), f.begin() + n / 2),
               f2 = vector<ll>(f.begin() + n / 2, f.end()),
               g1 = vector<ll>(g.begin(), g.begin() + n / 2),
               g2 = vector<ll>(g.begin() + n / 2, g.end());
    vector<ll> h1 = mul(f1, g1);
    for (int i = 0; i < n / 2; i++)
        f1[i] = (f1[i] + f2[i]) % mod,
        g1[i] = (g1[i] + g2[i]) % mod;
    g1 = mul(f1, g1);
    g2 = mul(f2, g2);
    h1.resize(2 * n, 0);
    for (int i = 0; i < n - 1; i++)
        g1[i] = (g1[i] - h1[i] - g2[i] + 2 * mod) % mod;
    for (int i = 0; i < n - 1; i++)
    {
        h1[i + n / 2] = (h1[i + n / 2] + g1[i]) % mod;
        h1[i + n] = (h1[i + n] + g2[i]) % mod;
    }
    h1.resize(m);
    return h1;
}

ll n, k, a, fac[100005];
map<int, int> mp, sz;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<ll> poly[100005];

signed main()
{
    fast;
    fac[0] = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int b = a;
        bool luck = 1;
        while (a)
        {
            luck &= (a % 10 == 4 || a % 10 == 7);
            a /= 10;
        }
        if (luck)
            mp[b]++;
        else
            sz[1]++;
    }
    for (auto [_, o] : mp)
        sz[o]++;
    int m = 0;
    for (auto [b, p] : sz)
    {
        m++;
        for (int i = 0; i <= p; i++)
            poly[m].emplace_back(fac[p] * inv(fac[i]) % mod * inv(fac[p - i]) % mod * fpow(b, i) % mod);
        pq.push(pii(poly[m].size(), m));
    }
    while (pq.size() > 1)
    {
        int i = pq.top().S;
        pq.pop();
        int j = pq.top().S;
        pq.pop();
        poly[i] = mul(poly[i], poly[j]);
        pq.push(pii(poly[i].size(), i));
    }
    int i = pq.top().S;
    poly[i].resize(k + 1, 0);
    cout << poly[i][k] << '\n';
}
