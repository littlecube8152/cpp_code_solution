#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;

int n, m;
vector<pair<int, int>> e[100001];
long long dis[100001];
bool fin[100001];
struct COMP
{
    bool operator()(const int &a, const int &b)
    {
        return dis[a] < dis[b];
    }
};

priority_queue<int, vector<int>, COMP> pq;

signed main()
{
    ///Dijkstra Ford SSSP
    cin >>
        n >> m;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        pq.push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[x].emplace_back(make_pair(y, w));
        e[y].emplace_back(make_pair(x, w));
    }

    dis[1] = 0;
    while (!pq.empty())
    {
        fin[pq.top()] = 1;
        for (auto i : e[pq.top()])
            if (!fin[i.first])
                dis[i.first] = min(dis[i.first], dis[pq.top()] + i.second);
        pq.pop();
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " \n"[i == n];
}