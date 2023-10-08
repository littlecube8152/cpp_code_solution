#include "train.h"
#include <bits/stdc++.h>
using namespace std;

int n, m, dead[5000];
vector<int> E[5000], R[5000];

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v)
{
	n = a.size(), m = u.size();
	vector<int> ans(n, 1);
	while (1)
	{
		for (int i = 0; i < n; i++)
			E[i].clear(), R[i].clear();
		for (int i = 0; i < m; i++)
			if (!dead[u[i]] && !dead[v[i]])
			{
				E[u[i]].emplace_back(v[i]);
				R[v[i]].emplace_back(u[i]);
			}

		vector<int> req(n, 0), vis(n, 0);
		for (int i = 0; i < n; i++)
			if (!dead[i])
			{
				if(r[i])
					req[i] = 0;
				else if (a[i])
					req[i] = 1;
				else
					req[i] = E[i].size();
			}

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (!dead[i] && r[i])
				q.emplace(i);
			

		while (!q.empty())
		{
			int i = q.front();
			vis[i] = 1;
			q.pop();
			for (auto j : R[i])
				if(--req[j] == 0)
					q.emplace(j);
		}

		for (int i = 0; i < n; i++)
			if (!dead[i])
			{
				if(!vis[i])
					req[i] = 0;
				else if (a[i])
					req[i] = E[i].size();
				else
					req[i] = 1;
			}
		for (int i = 0; i < n; i++)
			if(!dead[i] && !vis[i])
				q.emplace(i);
		if(q.empty())
			break;
		while (!q.empty())
		{
			int i = q.front();
			ans[i] = 0, dead[i] = 1;
			q.pop();
			for (auto j : R[i])
				if(--req[j] == 0)
					q.emplace(j);
		}
	}
	return ans;
}
