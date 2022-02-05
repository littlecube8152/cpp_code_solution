/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
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
using namespace __gnu_pbds;

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

ll n, m, deg[50005];
bitset<50005> b[50005];
vector<int> E[50005];
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        b[i][i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[v].emplace_back(u);
        deg[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : E[u])
        {
            b[i] |= b[u];
            if (--deg[i] == 0)
                q.push(i);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << b[i].count() << " \n"[i == n];
}
