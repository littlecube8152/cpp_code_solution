#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, w[50005], d[50005], ans = 1e18;
pll edge[50005];
bool recalcto[50005], recalcback[50005];
vector<ll> to, torev, back, backrev, recalctodis, recalcbackdis;
vector<int> tofrom, backfrom, tmp;
vector<int> E[205], rE[205];

pll get_edge(int id, int u)
{
    if (edge[id].F == u)
        return pll{edge[id].S, w[id]};
    else
        return pll{edge[id].F, w[id]};
}

void dijkstra(int begin, int N, vector<ll> &dis, vector<int> &from, vector<int> E[])
{
    dis = vector<ll>(N + 1, 1e18);
    dis[begin] = 0;
    from.resize(N + 1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, begin});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto id : E[u])
        {
            auto [v, w] = get_edge(id, u);
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
                from[v] = id;
            }
        }
    }
}

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        ll U, V, C, D;
        cin >> U >> V >> C >> D;
        edge[i] = {U, V};
        w[i] = C;
        d[i] = D;
        E[U].emplace_back(i);
        rE[V].emplace_back(i);
    }
    dijkstra(N, N, torev, tmp, rE);
    dijkstra(1, N, to, tofrom, E);
    dijkstra(1, N, backrev, tmp, rE);
    dijkstra(N, N, back, backfrom, E);
    //for (int i = 1; i <= N; i++)
    //    cout << to[i] << " \n"[i == N];
    //for (int i = 1; i <= N; i++)
    //    cout << back[i] << " \n"[i == N];
    if (to[N] < 1e18)
    {
        int cur = N;
        while (cur != 1)
        {
            int id = tofrom[cur];
            recalcto[id] = 1;
            cur = get_edge(id, cur).F;
        }
    }
    if (back[1] < 1e18)
    {
        int cur = 1;
        while (cur != N)
        {
            int id = backfrom[cur];
            recalcback[id] = 1;
            cur = get_edge(id, cur).F;
        }
    }
    ans = to[N] + back[1];
    //cerr << ans << '\n';
    for (int i = 1; i <= M; i++)
    {
        //cerr << i << " = ";
        ll res = d[i];
        if (recalcto[i])
        {
            //cout << " recalcto ";
            tie(edge[M + 1], w[M + 1]) = tie(edge[i], w[i]);
            w[i] = 1e18;
            E[edge[M + 1].S].emplace_back(M + 1);

            dijkstra(1, N, recalctodis, tmp, E);

            E[edge[M + 1].S].pop_back();
            tie(edge[i], w[i]) = tie(edge[M + 1], w[M + 1]);

            res += recalctodis[N];
        }
        else
            res += min(to[N], to[edge[i].S] + w[i] + torev[edge[i].F]);
        //cerr << res << " ";
        if (recalcback[i])
        {
            //cout << " recalcback ";
            tie(edge[M + 1], w[M + 1]) = tie(edge[i], w[i]);
            w[i] = 1e18;
            E[edge[M + 1].S].emplace_back(M + 1);

            dijkstra(N, N, recalcbackdis, tmp, E);

            E[edge[M + 1].S].pop_back();
            tie(edge[i], w[i]) = tie(edge[M + 1], w[M + 1]);

            res += recalcbackdis[1];
        }
        else
            res += min(back[1], back[edge[i].S] + w[i] + backrev[edge[i].F]);
        //cerr << res << "\n";
        ans = min(ans, res);
    }
    cout << (ans >= 1e18 ? -1 : ans) << '\n';
}