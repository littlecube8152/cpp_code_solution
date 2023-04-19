#pragma GCC optimize("Ofast,unroll-loops")
#ifndef EVAL
#include "grader.cpp"
#endif
#include "rect.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

namespace
{
	struct BIT
	{
		int bit[2501], N;
		void init(int n)
		{
			N = n;
			for (int i = 1; i < N; i++)
				bit[i] = 0;
		}
		void modify(int pos, int val)
		{
			for (int i = pos; i < N; i += (i & -i))
				bit[i] += val;
		}
		int query(int pos)
		{
			int ans = 0;
			for (int i = pos; i; i -= (i & -i))
				ans += bit[i];
			return ans;
		}

	} bit[2500];

	int N, M;
	pii table[2500][2500];
	vector<pii> ver[2500], hor[2500];
	vector<tuple<int, int, int, int>> event[2500];
	ll ans;

	void add_query(int l, int r, pii range)
	{
		if (range == pii(-1, -1))
			return;

		event[l].emplace_back(make_tuple(r, 0, range.F - 1, range.S + 1));
	}

	void add_modify(pii range, int u, int d)
	{
		if (range == pii(-1, -1))
			return;
		for (int i = range.F - 1; i <= range.S + 1; i++)
			event[i].emplace_back(make_tuple(range.S + 1, 1, u, d));
	}

	ll mango(vector<vector<int>> &a)
	{
		N = a.size(), M = a[0].size();

		if (N <= 2 || M <= 2)
			return 0;

		for (int i = 1; i + 1 < N; i++)
		{
			vector<pii> mono;
			for (int j = 0; j < M; j++)
			{
				while (!mono.empty() && mono.back().F < a[i][j])
				{
					if (j - mono.back().S >= 2)
						ver[i].emplace_back(pii(mono.back().S, j));
					mono.pop_back();
				}
				if (!mono.empty())
					if (j - mono.back().S >= 2)
						ver[i].emplace_back(pii(mono.back().S, j));
				if (!mono.empty() && mono.back().F == a[i][j])
					mono.back().S = j;
				else
					mono.emplace_back(pii(a[i][j], j));
			}
		}

		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				table[i][j] = pii(-1, -1);

		for (int i = 1; i + 1 < N; i++)
			for (auto [x, y] : ver[i])
				if (table[x][y].S == i - 1)
					table[x][y].S++;
				else
				{
					add_query(x, y, table[x][y]);
					table[x][y] = pii(i, i);
				}

		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				add_query(i, j, table[i][j]);

		for (int i = 1; i + 1 < M; i++)
		{
			vector<pii> mono;
			for (int j = 0; j < N; j++)
			{
				while (!mono.empty() && mono.back().F < a[j][i])
				{
					if (j - mono.back().S >= 2)
						hor[i].emplace_back(pii(mono.back().S, j));
					mono.pop_back();
				}
				if (!mono.empty())
					if (j - mono.back().S >= 2)
						hor[i].emplace_back(pii(mono.back().S, j));
				if (!mono.empty() && mono.back().F == a[j][i])
					mono.back().S = j;
				else
					mono.emplace_back(pii(a[j][i], j));
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				table[i][j] = pii(-1, -1);

		for (int i = 1; i + 1 < M; i++)
			for (auto [x, y] : hor[i])
				if (table[x][y].S == i - 1)
					table[x][y].S++;
				else
				{
					add_modify(table[x][y], x, y);
					table[x][y] = pii(i, i);
				}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				add_modify(table[i][j], i, j);

		for (int i = 0; i < N; i++)
			bit[i].init(N);
		for (int i = 0; i < M; i++)
		{
			sort(event[i].begin(), event[i].end(), greater<>());
			for (auto [_, t, l, r] : event[i])
			{
				if (t == 1)
					bit[l].modify(r, 1);
				else
					for (int j = l; j <= r; j++)
						ans += bit[j].query(r);
			}
			for (auto [_, t, l, r] : event[i])
				if (t == 1)
					bit[l].modify(r, -1);
		}
		return ans;
	}

}

ll count_rectangles(vector<vector<int>> a)
{
	return mango(a);
}