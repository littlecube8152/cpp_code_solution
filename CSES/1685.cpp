#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, vis[100005], cc[100005], d[100005], an[100005], dp[100005], dsu[200005];
vector<int> E[100005], rE[100005], cE[100005], order, leaf[100005], root;
vector<pii> sol;

int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void merge(int u, int v)
{
	u = find(u), v = find(v);
	dsu[u] = v;
}

void dfs(int u)
{
	vis[u] = 1;
	for (auto v : E[u])
		if(!vis[v])
			dfs(v);
	order.emplace_back(u);
}

void findscc(int u, int r)
{
	vis[u] = 0;
	cc[u] = r;
	an[r] = u;
	for (auto v : rE[u])
		if(vis[v] == 1)
			findscc(v, r);
}

void reach(int u, int r)
{
	vis[u] = 1;
	for (int v : cE[u])
		if(!vis[v])
			reach(v, r);
	if(cE[u].size() == 0)
		leaf[r].emplace_back(u);
}

void calc(int u)
{
	vis[u] = 0;
	for (int v : cE[u])
	{	
		if(vis[v])
			calc(v);
		dp[u] = dp[v];
	}
	if(cE[u].size() == 0)
	{
		//cerr << "leaf " << u << '\n';
		leaf[0].emplace_back(u);
		dp[u] = u;
	}
}

signed main()
{
    fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		rE[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++)
		if(!vis[i])
			dfs(i);
	reverse(order.begin(), order.end());
	m = 0;
	for (auto i : order)
		if(vis[i] == 1)
			findscc(i, ++m);
	for (int i = 1; i <= n; i++)
		for(auto j : E[i])
			if(cc[i] != cc[j])
			{	
				cE[cc[i]].emplace_back(cc[j]);
				//cerr << cc[i] << " -> " << cc[j] << '\n';
				d[cc[j]]++;
			}
	n = m;
	if(n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	assert(d[1] == 0);
	for (int i = 1; i <= n; i++)
		if(d[i] == 0 && !vis[i])
			reach(i, i);
	int last = leaf[1][0];
	for (int i = 2; i <= n; i++)
		if(!leaf[i].empty())
		{
			sol.emplace_back(pii(last, i));
			cE[last].emplace_back(i);
			d[i]++;
			last = leaf[i][0];
		}
	for (int i = 1; i <= n; i++)
	{	
		if(d[i] == 0)
			root.emplace_back(i);
		if(vis[i] == 1)
			calc(i);
	}
	while(leaf[0].size() > root.size())
	{
		sol.emplace_back(pii(leaf[0].back(), 1));
		leaf[0].pop_back();
	}
	int k = leaf[0].size();
	for (int i = 1; i <= n; i++)
		dsu[i] = i;
	for (int i = 1; i < k; i++)
	{
		int j = root[i], p = find(dp[j]), tmp, q;
		if(leaf[0].back() == p)
		{
			tmp = leaf[0].back();
			leaf[0].pop_back();
			sol.emplace_back(pii(q = leaf[0].back(), j));
			leaf[0].pop_back();
			leaf[0].emplace_back(tmp);
		}
		else
		{
			sol.emplace_back(pii(q = leaf[0].back(), j));
			leaf[0].pop_back();
		}
		merge(q, p);
	}
	// cerr << leaf[0].size() << '\n';
	assert(leaf[0].size() == 1);
	for(int i = k; i < root.size(); i++)
		sol.emplace_back(pii(leaf[0][0], root[i]));
	sol.emplace_back(pii(leaf[0][0], root[0]));
	cout << sol.size() << '\n';
	for(int i = 0; i < sol.size(); i++)
		cout << an[sol[i].F] << ' ' << an[sol[i].S] << '\n';
}
