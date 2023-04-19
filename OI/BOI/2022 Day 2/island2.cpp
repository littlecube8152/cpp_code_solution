#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, s[200005], pre[200005], ans[200005];
ll sz[200005], go[200005];
vector<int> E[200005];

void dfs(int u)
{
	for(int v : E[u])
		if(v != pre[u])
		{
			pre[v] = u;
			dfs(v);
			sz[u] += sz[v];
			if(sz[v] >= s[u])
				go[v] = 1;
		}
	sz[u] += s[u];
}

void ansdfs(int u)
{
	for(int v : E[u])
		if(v != pre[u] && go[v])
			ansdfs(v);
	ans[u] = 1;
}

signed main()
{
	cin >> N >> M;
	assert(M == N - 1);
	for(int i = 1; i <= N; i++)
		cin >> s[i];
	for(int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		if(u > v)
			swap(u, v);
		E[u].emplace_back(v);
	}	
	dfs(1);
	ansdfs(1);
	for(int i = 1; i <= N; i++)
		cout << ans[i];
	cout << '\n';
}
