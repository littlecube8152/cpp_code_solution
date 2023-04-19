#include "split.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, dsu[100000], rk[100000];

int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
	rk[x] += rk[y];
	dsu[y] = x;
}

int vis[100000];
vector<int> E[100000];
vector<pii> sz;
void dfs(int u, int color, int &cnt, vector<int> &sol)
{
	vis[u] = 1, cnt--;
	if (cnt < 0)
		sol[u] = sz[2].S;
	for (int v : E[u])
		if (!vis[v] && sol[v] == color)
			dfs(v, color, cnt, sol);
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

vector<int> find_split(int n, int a, int b, int c, vector<int> p, vector<int> q)
{
	N = n, M = p.size();
	sz.emplace_back(pii(a, 1));
	sz.emplace_back(pii(b, 2));
	sz.emplace_back(pii(c, 3));
	sort(sz.begin(), sz.end());
	a = sz[0].F, b = sz[1].F;
	vector<int> v;
	for (int i = 0; i < M; i++)
	{
		E[p[i]].emplace_back(q[i]);
		E[q[i]].emplace_back(p[i]);
		v.emplace_back(i);
	}

	int t = 1000;
	while (t--)
	{
		multiset<int, greater<int>> ms;
		for (int i = 0; i < N; i++)
		{
			dsu[i] = i, rk[i] = 1;
			ms.insert(1);
		}
		shuffle(v.begin(), v.end(), rd);
		for (int i : v)
		{
			int u = find(p[i]), v = find(q[i]);
			if (u == v)
				continue;

			ms.erase(ms.find(rk[u])), ms.erase(ms.find(rk[v])), ms.insert(rk[u] + rk[v]);
			merge(u, v);
			if (ms.size() >= 2 && *ms.begin() >= b && *next(ms.begin()) >= a)
				break;
		}
		if (ms.size() >= 2 && *ms.begin() >= b && *next(ms.begin()) >= a)
		{
			vector<int> sol(N, sz[2].S);
			int ra, rb;
			for (int i = 0; i < N; i++)
				if (rk[i] >= b && dsu[i] == i)
				{
					rb = i;
					break;
				}
			for (int i = 0; i < N; i++)
				if (rk[i] >= a && dsu[i] == i && i != rb)
				{
					ra = i;
					break;
				}
			
			for (int i = 0; i < N; i++)
			{
				int j = find(i);
				if (j == ra)
					sol[i] = sz[0].S;
				else if (j == rb)
					sol[i] = sz[1].S;
			}
			dfs(ra, sz[0].S, a, sol);
			dfs(rb, sz[1].S, b, sol);
			return sol;
		}
	}
	return vector<int>(N, 0);
}
