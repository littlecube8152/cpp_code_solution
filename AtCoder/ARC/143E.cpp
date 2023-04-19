/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, pre[200005], d[200005];
char c[200005];
vector<int> E[200005], topo[200005];

void dfs(int u)
{
    for (auto v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dfs(v);
        }
    if (c[u] == 'B')
    {
        topo[pre[u]].emplace_back(u);
        d[u]++;
    }
    else if (u != 1)
    {

        topo[u].emplace_back(pre[u]);
        d[pre[u]]++;
        c[pre[u]] = (c[pre[u]] == 'W' ? 'B' : 'W');
    }
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    if ((count(c + 1, c + 1 + N, 'B') + N - 1) % 2 == 1)
        cout << -1 << '\n';
    else
    {
        dfs(1);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= N; i++)
            if(d[i] == 0)
                pq.push(i);
        for (int i = 1; i <= N; i++)
        {
            int u = pq.top();
            pq.pop();
            for(auto v : E[u])
                if(--d[v] == 0)
                    pq.push(v);
            cout << u << " \n"[i == N];
        }
    }
}
