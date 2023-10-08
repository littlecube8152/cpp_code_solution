#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj, tree, trees, ans;
vector<int> cc, subtree;

void dfs(int u, int r, vector<vector<int>> &adj, vector<int> &cc)
{
	cc[u] = r;
	for (int v = 0; v < n; v++)
		if (adj[u][v] && cc[v] == -1)
			dfs(v, r, adj, cc);
}

int construct(vector<vector<int>> p)
{
	n = p.size();
	adj = tree = ans = vector<vector<int>>(n, vector<int>(n, 0));
	cc = subtree = vector<int>(n, -1);
	trees.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			adj[i][j] = p[i][j] > 0;
			tree[i][j] = p[i][j] == 1;
			if (p[i][j] == 3)
				return 0;
		}
	for (int i = 0; i < n; i++)
		if (cc[i] == -1)
			dfs(i, i, adj, cc);
	for (int i = 0; i < n; i++)
		if (subtree[i] == -1)
			dfs(i, i, tree, subtree);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (cc[i] != cc[j])
			{
				if (p[i][j] != 0)
					return 0;
			}
			else if (cc[i] == cc[j] && subtree[i] != subtree[j])
			{
				if (p[i][j] != 2)
					return 0;
			}
			else
			{
				if (p[i][j] != 1)
					return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (subtree[i] != i)
			ans[i][subtree[i]] = ans[subtree[i]][i] = 1;
		else if(subtree[i] == i)
			trees[cc[i]].emplace_back(i);
	for (int i = 0; i < n; i++)
		if(trees[i].size() <= 1)
			continue;
		else if(trees[i].size() == 2)
			return 0;
		else
		{
			int k = trees[i].size();
			for (int j = 0; j < k; j++)
				ans[trees[i][j]][trees[i][(j + 1) % k]] = ans[trees[i][(j + 1) % k]][trees[i][j]] = 1;
		}
	
	build(ans);
	return 1;
}
