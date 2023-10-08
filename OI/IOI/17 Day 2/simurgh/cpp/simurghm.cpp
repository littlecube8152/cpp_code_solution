#include "simurgh.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int vis[505], cc[505], base[505], out[505], no[505 * 505];
vector<pii> E[505];
vector<int> tree, ans;

void dfs(int u, int c)
{
	vis[u] = 1;
	cc[u] = c;
	for (auto [v, i] : E[u])
		if (!vis[v])
		{
			tree.emplace_back(i);
			dfs(v, c);
		}
}

vector<int> find_roads(int n, vector<int> u, vector<int> v)
{
	int m = u.size();
	for (int i = 0; i < m; i++)
	{
		E[u[i]].emplace_back(pii(v[i], i));
		E[v[i]].emplace_back(pii(u[i], i));
	}
	for (int i = 0; i < n; i++)
	{
		tree.clear();
		for (int j = 0; j < n; j++)
			vis[j] = 0, base[j] = -1, out[j] = -1;
		vis[i] = 1;
		for (auto j = 0; j < n; j++)
			if (!vis[j])
				dfs(j, j);
		// check
		vector<tuple<int, int, int>> queries;
		for (auto [j, id] : E[i])
			out[cc[j]] = id;
		
		for (auto [j, id] : E[i])
		{
			if(no[id])
				continue;
			vector<int> query = tree;
			for (int k = 0; k < n; k++)
				if (k != cc[j] && out[k] >= 0)
					query.emplace_back(out[k]);
			query.emplace_back(id);
			int res = count_common_roads(query);
			base[cc[j]] = max(base[cc[j]], res);
			queries.emplace_back(make_tuple(j, id, res));
		}
		for (auto [j, id, res] : queries)
			if (res == base[cc[j]])
				ans.emplace_back(id);
			else
				no[id] = 1;
	}	
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	return ans;
}
