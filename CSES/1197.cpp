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

int n, m, found;
ll dis[2505], pre[2505], vis[2505];
vector<pair<pii, ll>> E;
vector<int> v;

int dfs(int k, int r)
{
    vis[k] = r;
    if (found)
        return found;
    int i = pre[k];

    if (i == 0)
        return 0;

    if (!vis[i])
        return dfs(i, r);
    else if (vis[i] == r)
        return i;
    else
        return 0;
}

signed main()
{
    //fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E.emplace_back(pair<pii, ll>{pii{u, v}, w});
    }
    /* Why setting all distances to 0 is valid?
    We only notice whether negative cycle exists, 
    Since negative cycle exists, partition the cycle to some chain by the junction of the non-negative and negative weight edges
    There at least exists an negative > the next positive in all negative cycles (otherwise the cycle is not negative)
    Therefore, the node update will done in |{cycle nodes}| <= |V| times.
    */
    for (int i = 2; i <= n; i++)
        dis[i] = 0;
    for (int t = 1; t <= n + 9; t++)
        for (auto e : E)
            if (dis[e.F.F] <= 1e16)
                if (dis[e.F.F] + e.S < dis[e.F.S])
                    dis[e.F.S] = dis[e.F.F] + e.S, pre[e.F.S] = e.F.F;
    for (int i = 1; i <= n; i++)
    {
        //cout << pre[i] << " " << dis[i] << '\n';
        if (!vis[i] && !found)
            found = dfs(i, i);
    }

    if (found)
    {
        int cur = found;
        do
        {
            v.emplace_back(cur);
            cur = pre[cur];
        } while (cur != found);
        cout << "YES\n";
        reverse(v.begin(), v.end());
        cout << found;
        for (int i : v)
            cout << " " << i ;
    }
    else
        cout << "NO\n";
}
