// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma target("avx,avx2,sse,sse2,ssse3,sse4,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T, N, M, s[1200005], e[1200005], deg[5400005], fr[1200005], to[1200005], pre[1200005][18], ts;
pii io[1200005];
vector<int> E[1200005], topo[5400006]; 

inline int idx(int u, int p = 0, int type = -1)
{
	return (2 * p + 1 + type) * N + u;
}

inline void dfs(int u)
{
	io[u].F = ++ts;
	for(int p = 1; p <= 17; p++)
	{
		pre[u][p] = pre[pre[u][p - 1]][p - 1];
		topo[idx(u, 		  p-1, 0)].emplace_back(idx(u, p, 0));
		topo[idx(pre[u][p-1], p-1, 0)].emplace_back(idx(u, p, 0));
		topo[idx(u, p, 1)].emplace_back(idx(u, 			 p-1, 1));
		topo[idx(u, p, 1)].emplace_back(idx(pre[u][p-1], p-1, 1));
	}
	if(s[pre[u][0]])
		topo[s[pre[u][0]]].emplace_back(idx(u, 0, 0));
	if(e[pre[u][0]])
		topo[idx(u, 0, 1)].emplace_back(e[pre[u][0]]);

	for(int v : E[u])
		if(pre[u][0] != v)
		{
			pre[v][0] = u;
			dfs(v);
		}
	io[u].S = ts;
}
inline void addedge(int pos, int i)
{
	// cout << pos << ' ' << i << '\n';
	if(s[pos] && s[pos] != i)
		topo[s[pos]].emplace_back(i);
	if(e[pos] && e[pos] != i)
		topo[i].emplace_back(e[pos]);
}

inline bool isSubtree(int r, int c)
{
	return io[r].F <= io[c].F && io[c].S <= io[r].S;
}

inline int jump(int u, int v, int i)
{
	for(int p = 17; p >= 0; p--)
		if(!isSubtree(pre[u][p], v))
		{
			topo[i].emplace_back(idx(u, p, 1));
			topo[idx(u, p, 0)].emplace_back(i);
			// cout << u << ' ' << p << ' ' << i << '\n';
			u = pre[u][p];
		}
	return u;
}

inline void solve()
{
	ts = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		pre[i][0] = s[i] = e[i] = 0;
		E[i].clear();
	}
	for(int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	
	for(int p = 0; p <= 17; p++)
		pre[1][p] = 1;
		
	cin >> M;
	
	for(int i = 1; i <= 36 * N; i++)
	{
		deg[i] = 0;
		topo[i].clear();
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> fr[i] >> to[i];
		s[fr[i]] = i;
		e[to[i]] = i;
	}

	dfs(1);

	for(int i = 1; i <= M; i++)
	{
		int u = fr[i], v = to[i];
		addedge(u, i);
		addedge(v, i);

		if(pre[u][0] == v || pre[v][0] == u) continue;
		
		if(isSubtree(u, v))
			jump(v, u, i);
		else if(isSubtree(v, u))
			jump(u, v, i);
		else
		{	
			int lca = jump(u, v, i);
			jump(v, u, i);
			addedge(pre[lca][0], i);
		}
	}

	for(int i = 1; i <= 36 * N; i++)
		for(int j : topo[i])
		{	
			// cout << i << "->" << j << '\n';
			deg[j]++;
		}
	
	queue<int> q;
	for(int i = 1; i <= 36 * N; i++)
		if(deg[i] == 0)
			q.emplace(i);

	for(int t = 1; t <= 36 * N; t++)
	{
		if(q.empty())
		{
			cout << "No\n";
			return;
		}
		int u = q.front();
		q.pop();
		for(int v : topo[u])
		{
			deg[v]--;
			if(deg[v] == 0)
				q.emplace(v);
		}
	}
	cout << "Yes\n";
}



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--)
	{
		solve();
	}
}
