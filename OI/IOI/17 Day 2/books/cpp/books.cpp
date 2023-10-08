#pragma GCC optimize("Ofast,unroll-loops")
#include "books.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, reach[1000006], g[1000006], l, r;
vector<int> out[1000006];
long long minimum_walk(vector<int> p, int s)
{
	{
		n = p.size();
		int l = 0, r = n - 1;
		while (l < s && p[l] == l)
			l++;
		while (r > s && p[r] == r)
			r--;
		p = vector<int>(p.begin() + l, p.begin() + r + 1);
		n = p.size();
		s -= l;
		for (auto &i : p)
			i -= l;
	}

	ll ans = 0;

	vector<pii> edge;
	for (int i = 0; i < n; i++)
		reach[i] = i;
	for (int i = 0; i < n; i++)
	{
		ans += abs(p[i] - i);
		int u = min(p[i], i), v = max(p[i], i);
		if (v <= s || s <= u)
			reach[u] = max(reach[u], v);
		else
			edge.emplace_back(pii(u, v));
	}
	for (int i = 1; i < n; i++)
		reach[i] = max(reach[i - 1], reach[i]);
	int last = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		if (last < i)
			++m;
		g[i] = m;
		last = max(last, reach[i]);
	}
	int L = g[s], R = g[s];
	for (auto &[u, v] : edge)
	{
		u = g[u], v = g[v];
		L = min(L, u);
		R = max(R, v);
		out[u].emplace_back(v);
		out[v].emplace_back(u);
	}
	ans += 2 * (L + m - R);
	int l = g[s] + 1, r = g[s] - 1;
	ans -= 2;
	while (L < l || r < R)
	{
		ans += 2;
		int nl = max(L, l - 1), nr = min(R, r + 1);
		while (nl < l || r < nr)
		{
			if (nl < l)
			{
				l--;
				for (auto i : out[l])
					nl = min(i, nl), nr = max(i, nr);
			}
			else
			{
				r++;
				for (auto i : out[r])
					nl = min(i, nl), nr = max(i, nr);
			}
		}
	}

	return ans;
}
