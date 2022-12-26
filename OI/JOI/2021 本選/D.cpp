#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct edge
{
    ll to, color, weight, sum;
};

int N, M;
ll dis[100005];
vector<edge> E[100005];
map<int, pll> colorvis[100005], colorid[100005], colorlr[100005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 2; i <= N; i++)
        dis[i] = 1e17;
    for (int i = 1; i <= M; i++)
    {
        ll A, B, C, P;
        cin >> A >> B >> C >> P;
        E[A].emplace_back(edge{B, C, P, 0});
        E[B].emplace_back(edge{A, C, P, 0});
    }
    for (int i = 1; i <= N; i++)
        sort(E[i].begin(), E[i].end(), [](edge e1, edge e2)
             { return e1.color < e2.color; });
    for (int i = 1; i <= N; i++)
    {
        int l = 0, r = 0;

        for (; l < E[i].size();)
        {
            ll sum = 0;
            vector<pll> w;
            while (r < E[i].size() && E[i][r].color == E[i][l].color)
            {
                sum += E[i][r].weight;
                w.emplace_back(pll{E[i][r].weight, r});
                r++;
            }
            sort(w.begin(), w.end(), greater<>());
            if (w.size() == 1)
                colorvis[i][E[i][l].color] = {w[0].F, w[0].F};
            else
                colorvis[i][E[i][l].color] = {w[0].F, w[1].F};
            colorid[i][E[i][l].color] = {w[0].S, w[0].S};
            for (int k = l; k < r; k++)
                E[i][k].sum = sum;
            colorlr[i][E[i][l].color] = {l, r};
            l = r;
        }
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {

        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v, c, w, s] : E[u])
        {
            w = min(w, s - w);
            if (dis[v] > d + w)
                dis[v] = d + w, pq.push({d + w, v});
        }
        for (int i = 0; i < E[u].size(); i++)
        {
            auto [v, c, w, s] = E[u][i];
            auto iter = colorvis[v].find(c);
            if (iter->S.F == w || iter->S.S == w)
            {
                if (iter->S.F == w)
                    iter->S.F = 0;
                else
                    iter->S.S = 0;
                for (int j = colorlr[v][c].F; j < colorlr[v][c].S; j++)
                {
                    auto [v2, _, w2, s2] = E[v][j];
                    if (v2 != u)
                    {
                        w2 = min(w2, s2 - w - w2) + w;
                        if (dis[v2] > d + w2)
                            dis[v2] = d + w2, pq.push({d + w2, v2});
                    }
                }
            }
            else
            {
                auto [v2, _, w2, s2] = E[v][colorid[v][c].F];
                if (v2 != u)
                {
                    w2 = min(w2, s2 - w - w2) + w;
                    if (dis[v2] > d + w2)
                        dis[v2] = d + w2, pq.push({d + w2, v2});
                }
            }
        }
    }
    cout << (dis[N] >= 1e17 ? -1 : dis[N]) << '\n';
}