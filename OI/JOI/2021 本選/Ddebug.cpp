#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct edge
{
    ll to, color, weight;
};

int N, M;
ll dis[100005];
vector<edge> E[100005], oE[100005];
map<int, pii> colorvis[100005];
map<int, int> in[100005];

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
        E[A].emplace_back(edge{B, C, P});
        E[B].emplace_back(edge{A, C, P});
    }
    for (int i = 1; i <= N; i++)
        sort(E[i].begin(), E[i].end(), [](edge e1, edge e2)
             { return e1.color < e2.color; });
    for (int i = 1; i <= N; i++)
    {
        oE[i] = E[i];
        int l = 0, r = 0;
        ll sum = 0;
        for (; l < E[i].size();)
        {
            while (r < E[i].size() && E[i][r].color == E[i][l].color)
            {
                sum += E[i][r].weight;
                r++;
            }
            for (int k = l; k < r; k++)
                E[i][k].weight = min(E[i][k].weight, sum - E[i][k].weight);
            sum = 0;
            if (r - l == 2)
            {
                in[i][E[i][l].to] = E[i][l + 1].to;
                in[i][E[i][l + 1].to] = E[i][l].to;
            }
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
        for (auto [v, c, w] : E[u])
        {
            if (dis[v] > d + w)
                dis[v] = d + w, pq.push({d + w, v});
        }
        for (auto [v, c, w] : oE[u])
        {
            auto iter = in[v].find(u);
            if (iter != in[v].end())
                if (dis[iter->S] > d + w)
                    dis[iter->S] = d + w, pq.push({d + w, iter->S});
        }
    }
    for (int i = 1; i <= N; i++)
        cout << dis[i] << " \n"[i == N];
    cout << (dis[N] >= 1e15 ? -1 : dis[N]) << '\n';
}