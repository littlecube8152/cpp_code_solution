/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, idx = 1, dis[500005], vis[500005], isrock[500005];
pii s, g, p[500005];
vector<pii> xmove, ymove;
vector<int> E[500005];
map<pii, int> mp;

signed main()
{
    fast;
    cin >> N >> N >> N;
    cin >> p[1].F >> p[1].S >> g.F >> g.S;
    mp[p[1]] = 1;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                if (abs(dx) + abs(dy) <= 1)
                {
                    if (mp[{x + dx, y + dy}] == 0)
                        mp[{x + dx, y + dy}] = ++idx;
                    if (dx != 0)
                        ymove.emplace_back(pii{x + dx, y + dy});
                    else if (dy != 0)
                        xmove.emplace_back(pii{x + dx, y + dy});
                    else
                    {
                        isrock[idx] = 1;
                        xmove.emplace_back(pii{x + dx, y + dy});
                        ymove.emplace_back(pii{x + dx, y + dy});
                    }
                    p[idx] = pii{x + dx, y + dy};
                }
    }
    sort(xmove.begin(), xmove.end());
    for (int i = 1; i <= idx; i++)
        if (!isrock[i])
        {
            auto iter = upper_bound(xmove.begin(), xmove.end(), p[i]);
            if (iter != xmove.end() && p[i].F == iter->F)
                E[i].emplace_back(mp[*iter]);
            iter = lower_bound(xmove.begin(), xmove.end(), p[i]);
            if (iter != xmove.begin())
            {
                --iter;
                if (p[i].F == iter->F)
                    E[i].emplace_back(mp[*iter]);
            }
        }

    sort(ymove.begin(), ymove.end(), [&](pii p1, pii p2)
         { return pii{p1.S, p1.F} < pii{p2.S, p2.F}; });
    for (int i = 1; i <= idx; i++)
        if (!isrock[i])
        {
            auto iter = upper_bound(ymove.begin(), ymove.end(), p[i], [&](pii p1, pii p2)
                                    { return pii{p1.S, p1.F} < pii{p2.S, p2.F}; });
            if (iter != ymove.end() && p[i].S == iter->S)
                E[i].emplace_back(mp[*iter]);
            iter = lower_bound(ymove.begin(), ymove.end(), p[i], [&](pii p1, pii p2)
                               { return pii{p1.S, p1.F} < pii{p2.S, p2.F}; });
            if (iter != ymove.begin())
            {
                --iter;
                if (p[i].S == iter->S)
                    E[i].emplace_back(mp[*iter]);
            }
        }

    queue<int> q;
    for (int i = 2; i <= idx; i++)
        dis[i] = 1e9;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i : E[u])
            if (!vis[i])
            {
                dis[i] = min(dis[i], dis[u] + 1);
                q.push(i);
            }
    }/*
    for (int u = 1; u <= idx; u++)
    {
        cout << u << "    ";
        for (int i : E[u])
            cout << i << " ";
        cout << '\n';
    }
    for (int i = 1; i <= idx; i++)
        cout << dis[i] << " \n"[i == idx];
    for (int i = 1; i <= idx; i++)
        cout << i << " (" << p[i].F << ", " << p[i].S << ")\n";*/
    if (mp[g] == 0 || dis[mp[g]] > 1e8)
        cout << -1 << '\n';
    else
        cout << dis[mp[g]] << '\n';
}
