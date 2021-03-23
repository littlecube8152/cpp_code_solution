#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;

struct edge
{
    int x, y, w;
};

int n, m;
vector<edge> e;
long long dis[100001];

signed main()
{
    ///Bellman Ford SSSP
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.emplace_back(edge{x, y, w});
    }

    dis[1] = 0;
    for (int i = 1; i <= n; i++)
        for (auto j : e)
            if (dis[j.x] > dis[j.y])
                dis[j.x] = min(dis[j.y] + j.w, dis[j.x]);
            else if (dis[j.x] < dis[j.y])
                dis[j.y] = min(dis[j.x] + j.w, dis[j.y]);

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " \n"[i == n];
}