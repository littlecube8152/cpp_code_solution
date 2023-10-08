#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
using namespace std;
// todo: change edge stroage in order to simplify code length

template <int V>
struct dinic
{
	const ll INF = 1e18;
	ll adjptr[V + 1], dis[V + 1], vis[V + 1], s, t, ans;
	struct edge
	{
		ll u, v, cap;
	};
	vector<edge> e;
	vector<int> adj[V + 1];
	bool bfs()
	{
		for (int i = 1; i <= V; i++)
			dis[i] = (i == s ? 0 : V + 1);
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto id : adj[u])
			{
				auto [_, v, cap] = e[id];
				if (dis[v] > V && cap > 0)
				{
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[t] <= V;
	}

	vector<pii> find_cut()
	{
		vector<pii> cut;
		bfs();
		for (int i = 0; i < e.size(); i += 2)
			if (dis[e[i].u] <= V && dis[e[i].v] > V)
				cut.emplace_back(pii(e[i].u, e[i].v));
		return cut;
	}
	ll dfs(int u, ll flow)
	{
		if (u == t || !flow)
			return flow;
		for (; adjptr[u] < (int)adj[u].size(); adjptr[u]++)
		{
			int d = adj[u][adjptr[u]];
			auto [_, v, cap] = e[d];
			if (cap <= 0 || vis[v] || dis[v] != dis[u] + 1)
				continue;
			vis[v] = 1;
			ll f = dfs(v, min(flow, cap));
			if (f)
			{
				e[d].cap -= f, e[d ^ 1].cap += f;
				return f;
			}
		}
		return 0;
	}
	void add_edge(int u, int v, ll c)
	{
		adj[u].emplace_back(e.size());
		e.emplace_back(edge{u, v, c});
		adj[v].emplace_back(e.size());
		e.emplace_back(edge{v, u, 0});
	}
	ll flow(int S, int T)
	{
		s = S, t = T;
		for (int i = 0; i < (int)e.size(); i += 2)
			e[i].cap = e[i].cap + e[i ^ 1].cap, e[i ^ 1].cap = 0;
		while (bfs())
		{
			for (int i = 1; i <= V; i++)
				adjptr[i] = 0, vis[i] = 0;
			ll f = 1;
			while (f)
				ans += (f = dfs(s, INF));
		}
		return ans;
	}
};
