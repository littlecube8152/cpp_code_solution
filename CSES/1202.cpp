/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m;
bool vis[100005];
ll dis[100005], cnt[100005], mx[100005], mi[100005];
vector<pll> E[100005];
priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>>> pq;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(pll{v, w});
    }

    for (int i = 1; i <= n; i++)
        dis[i] = mi[i] = 1e17;
    mi[1] = 0;
    cnt[1] = 1;
    dis[1] = 0;
    pq.push({make_pair(0, 1), 0});

    while (!pq.empty())
    {
        auto p = pq.top().F;
        ll num = pq.top().S;
        pq.pop();
        if (p.F <= dis[p.S] && num == mx[p.S])
            for (pll e : E[p.S])
            {
                if (p.F + e.S < dis[e.F])
                {
                    dis[e.F] = p.F + e.S;
                    mx[e.F] = num + 1;
                    pq.push({make_pair(p.F + e.S, e.F), num + 1});
                }
                else if (p.F + e.S == dis[e.F] && num + 1 > mx[e.F])
                {
                    mx[e.F] = num + 1;
                    pq.push({make_pair(p.F + e.S, e.F), num + 1});
                }
            }
    }

    dis[1] = 0;
    pq.push({make_pair(0, 1), 0});
    for (int i = 1; i <= n; i++)
        dis[i] = 1e17;

    while (!pq.empty())
    {
        auto p = pq.top().F;
        ll num = pq.top().S;
        pq.pop();
        if (p.F <= dis[p.S] && num == mi[p.S])
            for (pll e : E[p.S])
            {
                if (p.F + e.S < dis[e.F])
                {
                    dis[e.F] = p.F + e.S;
                    mi[e.F] = num + 1;
                    pq.push({make_pair(p.F + e.S, e.F), num + 1});
                }
                else if (p.F + e.S == dis[e.F] && num + 1 < mi[e.F])
                {
                    mi[e.F] = num + 1;
                    pq.push({make_pair(p.F + e.S, e.F), num + 1});
                }
            }
    }

    dis[1] = 0;
    pq.push({make_pair(0, 1), 1});
    for (int i = 1; i <= n; i++)
        dis[i] = 1e17;

    while (!pq.empty())
    {
        auto p = pq.top().F;
        ll num = pq.top().S;
        pq.pop();
        if (p.F <= dis[p.S])
            for (pll e : E[p.S])
            {
                if (p.F + e.S < dis[e.F])
                {
                    dis[e.F] = p.F + e.S;
                    cnt[e.F] = cnt[p.S];
                    pq.push({make_pair(p.F + e.S, e.F), 1});
                }
                else if (p.F + e.S == dis[e.F])
                {
                    cnt[e.F] = (cnt[e.F] + cnt[p.S]) % MOD;
                }
            }
    }

    cout << dis[n] << " " << cnt[n] << " " << mi[n] << " " << mx[n];
}
