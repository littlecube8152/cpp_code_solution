#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;

struct edge
{
    int x, y, w;
};

int n, m;
vector<edge> e;
long long dis[1001][1001];

signed main()
{
    ///Floyd-Warshall APSP
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[[i][j] = INF;

    for (int i = 1; i <= m; i++)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        dis[x][y] =  w;
        dis[y][x] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << dis[i][j] << " \n"[j == n];
}