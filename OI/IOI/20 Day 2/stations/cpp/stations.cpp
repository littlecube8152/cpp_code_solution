#include "stations.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int t, vis[1000];
vector<int> E[1000], labels;

// type 0: first, 1: last
void dfs(int u, int type)
{
	vis[u] = 1;
	if (type == 0)
		labels[u] = t++;
	for (auto v : E[u])
		if (!vis[v])
			dfs(v, type ^ 1);
	if (type == 1)
		labels[u] = t++;
}

vector<int> label(int n, int k, vector<int> u, vector<int> v)
{
	t = 0;
	for (int i = 0; i < n; i++)
		E[i].clear(), vis[i] = 0;
	for (int i = 0; i < n - 1; i++)
		E[u[i]].emplace_back(v[i]), E[v[i]].emplace_back(u[i]);
	labels.clear();
	labels.resize(n);
	dfs(0, 0);
	return labels;
}

int find_next_station(int s, int t, vector<int> c)
{
	int root = -1;
	if (s < c[0])
	{
		if (s != 0)
		{
			root = c.back();
			c.pop_back();
		}
		int pre = s;
		for (int a : c)
		{
			if (pre <= t && t <= a)
				return a;
			pre = a + 1;
		}
	}
	else
	{
		reverse(c.begin(), c.end());
		if (s != 0)
		{
			root = c.back();
			c.pop_back();
		}
		int last = s;
		for (int a : c)
		{
			if (a <= t && t <= last)
				return a;
			last = a - 1;
		}
	}
	return root;
}
