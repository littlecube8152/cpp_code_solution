#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m, k, out[300000], vis[300000], res[300000];
set<int> keys[300000];
vector<int> edge[600000], reach[300000];
map<int, int> mp[300000];

struct dsu
{
	int dsu[300000], rk[300000];
	void init()
	{
		for (int i = 0; i < n; i++)
			dsu[i] = i, rk[i] = 1;
	}
	int find(int k)
	{
		return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
	}
} ptree, scc;

void merge(vector<int> &a, vector<int> &b)
{
	if (a.size() < b.size())
		swap(a, b);
	for (auto i : b)
		a.emplace_back(i);
	b.clear();
}

vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c)
{
	n = r.size();
	m = u.size();
	ptree.init(), scc.init();
	for (int i = 0; i < n; i++)
		keys[i].insert(r[i]);

	for (int i = 0; i < m; i++)
	{
		if (mp[u[i]][c[i]] == 0)
			mp[u[i]][c[i]] = ++k;
		if (mp[v[i]][c[i]] == 0)
			mp[v[i]][c[i]] = ++k;
		edge[mp[u[i]][c[i]]].emplace_back(v[i]);
		edge[mp[v[i]][c[i]]].emplace_back(u[i]);
	}
	for (int i = 0; i < n; i++)
		out[i] = i, res[i] = n + 1;
	for (int i = 0; i < n; i++)
		if (mp[i].find(r[i]) != mp[i].end())
		{
			auto iter = mp[i].find(r[i]);
			int p = iter->second;
			mp[i].erase(iter);
			merge(reach[i], edge[p]);
		}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; i++)
		pq.push(pii(1, i));
	int last = n + 1;
	while (!pq.empty())
	{
		auto [s, u] = pq.top();
		// u should be the root of pseudo-trees and the representative of its scc
		pq.pop();

		if (s > last)
			break;

		while (!reach[u].empty() && scc.find(reach[u].back()) == u)
			reach[u].pop_back();
		if (reach[u].empty())
		{
			// not augumentable, check until all scc > s
			res[u] = s;
			last = s;
			continue;
		}
		int v = scc.find(reach[u].back());
		if (ptree.find(v) != u)
		{
			out[u] = v, ptree.dsu[u] = ptree.find(v);
			continue;
		}
		// augument
		while (v != u)
		{
			int nxt = scc.find(out[v]);
			// if (keys[v].size() > keys[u].size())
			// {
			// 	swap(out[u], out[v]);
			// 	swap(u, v);
			// }
			merge(reach[u], reach[v]);

			for (auto i : keys[v])
				if (keys[u].find(i) == keys[u].end())
				{
					keys[u].insert(i);
					auto iter = mp[u].find(i);
					if (iter != mp[u].end())
					{
						int p = iter->second;
						mp[u].erase(iter);
						merge(reach[u], edge[p]);
					}
				}
			for (auto [c, p] : mp[v])
			{
				if (keys[u].find(c) != keys[u].end())
					merge(reach[u], edge[p]);
				else
				{
					int q = mp[u][c];
					if (q == 0)
						mp[u][c] = p;
					else
						merge(edge[q], edge[p]);
				}
			}
			ptree.dsu[v] = u;
			scc.dsu[v] = u;
			scc.rk[u] += scc.rk[v];

			v = nxt;
		}
		pq.push(pii(scc.rk[u], u));
	}
	for (int i = 0; i < n; i++)
		res[i] = res[scc.find(i)];
	last = *min_element(res, res + n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		ans[i] = res[i] == last;
	return ans;
}
