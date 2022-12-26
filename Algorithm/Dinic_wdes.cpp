#include <bits/stdc++.h>

using namespace std;

// Dinic Algorithm structure with 'V' vertices and capacity of type 'Cap'.
// Runs in O(V²E).
// Please ensure 'V' fits into int. (who will need flow of 2147483648 vertices graph in practice?)
template <typename Cap, int V>
struct dinic
{
    const Cap INF = numeric_limits<Cap>::max() / 2;
    int adjptr[V + 1], dis[V + 1], s, t;
    bool vis[V + 1];
    Cap ans = 0;
    // {from, to, capacity}
    vector<pair<pair<int, int>, Cap>> e;
    vector<int> adj[V + 1];

    // Helper function for BFS in Dinic Algorithm.
    // This function should be called O(V) times when call one time of flow(int S, int T).
    // Return true if still have residual flow.  
    bool bfs()
    {
        for (int i = 1; i <= V; i++)
            vis[i] = 0, dis[i] = V + 1;

        queue<int> q;
        q.push(s);
        vis[s] = 1, dis[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = e[adj[u][i]].first.second;
                if (!vis[v] && e[adj[u][i]].second > 0)
                {
                    dis[v] = dis[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if (dis[t] > V)
            return false;
        return true;
    }

    // Returns a min-cut after called flow(int S, int T)
    // This function should be called only after a call of flow(int S, int T).
    vector<pair<int, int>> find_cut()
    {
        vector<pair<int, int>> cut;
        for (int i = 1; i <= V; i++)
            vis[i] = 0, dis[i] = V + 1;

        queue<int> q;
        q.push(s);
        vis[s] = 1, dis[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = e[adj[u][i]].first.second;
                if (!vis[v] && e[adj[u][i]].second > 0)
                {
                    dis[v] = dis[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        for (int u = 1; u <= V; u++)
            if (vis[u])
                for (int i = 0; i < (int)adj[u].size(); i++)
                {
                    int v = e[adj[u][i]].first.second;
                    if (!vis[v] && adj[u][i] % 2 == 0)
                        cut.emplace_back(pair<int, int>{u, v});
                }
        return cut;
    }

    // Helper function for DFS in Dinic Algorithm.
    // This function should be called O(V) times when call one time of flow(int s, int t).
    // Each time runs in O(VE).
    Cap dfs(int k, Cap flow)
    {
        if (flow <= 0)
            return 0;
        if (k == t)
            return flow;
        for (; adjptr[k] < (int)adj[k].size(); adjptr[k]++)
        {
            int d = adj[k][adjptr[k]];
            if (e[d].second <= 0)
                continue;
            else if (vis[e[d].first.second])
                continue;
            else if (dis[e[d].first.second] != dis[k] + 1)
                continue;
            vis[e[d].first.second] = 1;
            Cap f = dfs(e[d].first.second, min(flow, e[d].second));
            if (f > 0)
            {
                e[d].second -= f;
                e[d ^ 1].second += f;
                return f;
            }
        }
        return 0;
    }

    // Add an edge u->c with capacity c to the flow network, directed.
    // For undirected add both directions seperately.
    // Please ensure u, v in [1, V].
    void add_edge(int u, int v, Cap c)
    {
        adj[u].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, Cap>{{u, v}, c});
        adj[v].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, Cap>{{v, u}, 0});
    }

    // Returns the max-flow of S-T.
    // Runs in O(V²E), please ensure the flow does not exceed INF/2 and S, T in [1, V].
    Cap flow(int S, int T)
    {
        this->s = S;
        this->t = T;
        for (int i = 0; i < (int)e.size(); i += 2)
        {
            e[i].second = e[i].second + e[i + 1].second;
            e[i + 1].second = 0;
        }

        while (bfs())
        {
            for (int i = 1; i <= V; i++)
                adjptr[i] = 0;
            while (true)
            {
                for (int i = 1; i <= V; i++)
                    vis[i] = 0;
                Cap f = dfs(s, INF);
                ans += f;
                if (f == 0)
                    break;
            }
        }
        return ans;
    }
};
