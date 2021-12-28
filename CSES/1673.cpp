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
ll dis[2505][2];
vector<pair<pii, ll>> E;

signed main()
{
    /* Note for this graph question:
    1.  some properties make the answer not valid, 
        but NOT ALWAYS make the answer valid.
    2.  make sure check all extreme tests, like
        a. negative cycle
        b. small changes but influences the answer after a lot of iterations
            ex. this problem
            1 ----> 4
            |  200  ∧
          1 |       | 0
            v   1   |
            2 <---> 3
                1
            ex. flow (ford-fulkerson)
            1 --1-- 4
            |     / |
            |    /  |
            1  1e6  1
            |  /    |
            | /     |
            2 --1-- 3
        c. not connected graph
        d. unreachable vertex
        e. multi edge
        f. self cycle
    */
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E.emplace_back(pair<pii, ll>{pii{u, v}, -w});
    }
    for (int i = 2; i <= n; i++)
        dis[i][0] = 1e17;
    for (int t = 1; t <= n; t++)
        for (auto e : E)
            if (dis[e.F.F][1] <= 1e16)
                dis[e.F.S][0] = min(dis[e.F.S][0], dis[e.F.F][0] + e.S);

    for (int i = 1; i <= n; i++)
        dis[i][1] = dis[i][0];

    for (auto e : E)
        if (dis[e.F.F][1] <= 1e16)
            dis[e.F.S][1] = min(dis[e.F.S][1], dis[e.F.F][1] + e.S);

    for (int i = 1; i <= n; i++)
        if (dis[i][0] != dis[i][1])
            dis[i][1] = -1;
        else
            dis[i][1] = 0;

    for (int t = 1; t <= n; t++)
        for (auto e : E)
            dis[e.F.S][1] = min(dis[e.F.S][1], dis[e.F.F][1]);

    if (dis[n][1] < 0)
        cout << -1;
    else
        cout << -dis[n][0];
}
