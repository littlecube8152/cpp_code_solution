#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, vis[300005];
vector<int> E[300005];

int dfs(int u, int r)
{
	int m = u;
	vis[u] = r;
	for (auto v : E[u])
		if(!vis[v])
			m = max(m, dfs(v, r));
	return m;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	vis[N] = -1;
	vector<pii> v;
	for (auto i : E[N])
		if(!vis[i])
			v.emplace_back(pii(dfs(i, i), i));		
	sort(v.begin(), v.end(), greater<>());
	for (int i = 1; i <= N; i++)
		if (vis[i] == v[0].S)
			cout << "B";
		else 
			cout << "A";
	cout << '\n';	
}
