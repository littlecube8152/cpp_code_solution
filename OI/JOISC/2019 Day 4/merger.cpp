#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int P = 20;
int N, K, pre[500005][P], block[500005], deg[500005], split[500005], down[500005], up[500005], t, cc;
vector<int> state[500005];
vector<pii> E[500005];
pii io[500005];


bool ischild(int r, int c)
{
	return io[r].F <= io[c].F && io[c].S <= io[r].S;
}

int lca(int u, int v)
{
	int l = u;
	for(int p = P - 1; p >= 0; p--)
		if(pre[l][p] && !ischild(pre[l][p], v))
			l = pre[l][p];
	if(!ischild(l, v))
		l = pre[l][0];
	return l;
}

void dfs(int u)
{
	io[u].F = ++t;
	for(auto [v, i] : E[u])
		if(v != pre[u][0])
		{
			pre[v][0] = u;
			dfs(v);
		}
	io[u].S = t;
}

int find_edge(int u)
{
	int cur = 0;
	for(auto [v, i] : E[u])
		if(v != pre[u][0])
		{	
			int child = find_edge(v);
			if(child == 0)
				split[i] = 1;
			cur += child;
		}
	// cerr << u << '=' << cur - down[u] + up[u] << '\n';
	return cur - down[u] + up[u];
}

void color(int u, int r)
{
	for(auto [v, i] : E[u])
		if(v != pre[u][0])
		{
			if(split[i])
			{
				// cerr << u << ' ' << v << '\n';	
				deg[r]++, deg[++cc]++;
				color(v, cc);
			}
			else
				color(v, r);
		}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		E[A].emplace_back(pii(B, i));
		E[B].emplace_back(pii(A, i));
	}
	dfs(1);
	for(int i = 1; i <= N; i++)
	{
		int S;
		cin >> S;
		state[S].emplace_back(i);
	}
	for(int p = 1; p < P; p++)
		for(int i = 1; i <= N; i++)
			pre[i][p] = pre[pre[i][p - 1]][p - 1];
	for(int i = 1; i <= K; i++)
	{
		for(int j = 1; j < state[i].size(); j++)
		{
			int u = state[i][j - 1], v = state[i][j], l = lca(u, v);
			if(l == u)
				up[v]++, down[u]++;
			else if(l == v)
				up[u]++, down[v]++;
			else
				up[u]++, up[v]++, down[l] += 2;
		}
	}
	find_edge(1);
	color(1, ++cc);
	int cnt = 0;
	for(int i = 1; i <= N; i++)
		if(deg[i] == 1)
			cnt++;
	cout << (cnt + 1) / 2 << '\n';
}
