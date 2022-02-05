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

int n, m, k;
bool vis[100005];
priority_queue<ll, vector<ll>, less<ll>> dis[100005];
vector<pll> E[100005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

signed main()
{
    //fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(pll{v, w});
    }
    dis[1].push(0);
    pq.push(make_pair(0, 1));
    for (int i = 1; i <= 10; i++)
    {
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if (p.F <= dis[p.S].top())
            {
                for (pll e : E[p.S])
                {

                    if (dis[e.F].size() < k)
                    {
                        dis[e.F].push(p.F + e.S);
                        pq.push(make_pair(p.F + e.S, e.F));
                    }
                    else if (dis[e.F].size() >= k && p.F + e.S < dis[e.F].top())
                    {
                        dis[e.F].pop();
                        dis[e.F].push(p.F + e.S);
                        pq.push(make_pair(p.F + e.S, e.F));
                    }
                }
            }
        }
    }
    deque<ll> ans;
    while (!dis[n].empty())
    {
        ans.push_front(dis[n].top());
        dis[n].pop();
    }
    for (ll i : ans)
        cout << i << " ";
}
