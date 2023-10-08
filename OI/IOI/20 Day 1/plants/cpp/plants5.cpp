#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int n, state[300];
vector<int> E[300];

void init(int k, vector<int> r)
{
	n = r.size();
	for (int i = 0; i < n; i++)
	{
		r[i] = k - 1 - r[i];
		if (r[i] == 0)
		{
			state[i] = 1;
			for (int t = 1; t < k; t++)
				E[i].emplace_back((i + t) % n);
		}
	}
	for (int it = 0; it < n; it++)
	{
		int cur = -1;
		for (int j = 0; j < n; j++)
			if (state[j] == 1)
			{
				int cnt = 0;
				for (int t = 1; t < k; t++)
					cnt += state[(j - t + n) % n] == 1;
				if (cnt == 0)
				{
					cur = j;
					break;
				}
			}
		state[cur] = 2;
		for (int t = 1; t < k; t++)
			if (--r[(cur - t + n) % n] == 0)
			{
				E[cur].emplace_back((cur - t + n) % n);
				state[(cur - t + n) % n] = 1;
			}

		for (int t = 1; t < k; t++)
			if (state[(cur + t) % n] <= 1)
				E[cur].emplace_back((cur + t) % n);
	}
	return;
}

bool reach(int x, int y)
{
	vector<int> vis(n, 0);
	queue<int> q;
	q.emplace(x);
	vis[x] = 1;
	while (!q.empty())
	{
		int u = q.front();
		if (u == y)
			return true;
		q.pop();
		for (auto v : E[u])
			if (!vis[v])
			{
				vis[v] = 1;
				q.emplace(v);
			}
	}
	return false;
}

int compare_plants(int x, int y)
{
	if (reach(x, y))
		return -1;
	if (reach(y, x))
		return 1;
	return 0;
}
