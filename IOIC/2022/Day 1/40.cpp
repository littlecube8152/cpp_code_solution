#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
const int GOAL = 1e6;
int main()
{
    stringstream ss;
    int n = 44, m;

    vector<pair<pii, int>> v;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v.emplace_back(make_pair(pii{i, j}, (j - i) * 2 - 1));
    m = v.size();
    for (int i = 1; n + i <= 1000; i++)
        v.emplace_back(make_pair(pii{n, n + i}, 1));
    n = 1000;
    m = v.size();
    cout << "n = " << n << ", m = " << m << '\n';
    vector<vector<pair<int, long long>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a = v[i].F.F, b = v[i].F.S;
        long long c = v[i].S;
        g[--a].emplace_back(--b, c);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, (long long)1e18);
    dist[0] = 0;
    pq.push(make_pair(0ll, 0));
    int round = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto [v, w] : g[u])
        {
            ++round;
            //assert(round < GOAL);
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << round << '\n';
    return 0;
}