#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int n, state[800005], order[200005], out[200005], in[200005];
bitset<2000> reachability[2000];

struct segTree
{
	pll seg[800005];
	ll lazy[800005];

	void init(int i = 1, int L = 0, int R = n - 1)
	{
		seg[i].S = L;
		if (L == R)
			return;
		int mid = (L + R) / 2;
		init(i << 1, L, mid);
		init(i << 1 | 1, mid + 1, R);
	}

	void modify(int mL, int mR, ll val, int i = 1, int L = 0, int R = n - 1)
	{
		if (mL <= L && R <= mR)
		{
			lazy[i] += val;
			seg[i].F += val;
		}
		else if (R < mL || mR < L)
			return;
		else
		{
			int mid = (L + R) / 2;
			lazy[i << 1] += lazy[i];
			lazy[i << 1 | 1] += lazy[i];
			seg[i << 1].F += lazy[i];
			seg[i << 1 | 1].F += lazy[i];
			lazy[i] = 0;
			modify(mL, mR, val, i << 1, L, mid);
			modify(mL, mR, val, i << 1 | 1, mid + 1, R);
			seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
		}
	}

	pll query(int qL, int qR, int i = 1, int L = 0, int R = n - 1)
	{
		if (qL <= L && R <= qR)
			return seg[i];
		else if (R < qL || qR < L)
			return pll(1e9, n + 1);
		else
		{
			int mid = (L + R) / 2;
			lazy[i << 1] += lazy[i];
			lazy[i << 1 | 1] += lazy[i];
			seg[i << 1].F += lazy[i];
			seg[i << 1 | 1].F += lazy[i];
			lazy[i] = 0;
			return min(query(qL, qR, i << 1, L, mid),
					   query(qL, qR, i << 1 | 1, mid + 1, R));
		}
	}
	void safe_modify(int l, int r, ll val)
	{
		if (l <= r)
			modify(l, r, val);
		else
		{
			modify(l, n - 1, val);
			modify(0, r, val);
		}
	}
} seg, zero;

struct changeValseg
{
	ll seg[800005];

	void init(int i = 1, int L = 0, int R = n - 1)
	{
		seg[i] = -1;
		if (L == R)
			return;
		int mid = (L + R) / 2;
		init(i << 1, L, mid);
		init(i << 1 | 1, mid + 1, R);
	}

	void modify(int mL, int mR, ll val, int i = 1, int L = 0, int R = n - 1)
	{
		if (mL <= L && R <= mR)
			seg[i] = val;
		else if (R < mL || mR < L)
			return;
		else
		{
			seg[i] = -1;
			int mid = (L + R) / 2;
			modify(mL, mR, val, i << 1, L, mid);
			modify(mL, mR, val, i << 1 | 1, mid + 1, R);
		}
	}

	ll query(int pos, int i = 1, int L = 0, int R = n - 1)
	{
		if (seg[i] != -1 || L == R)
			return seg[i];
		else
		{
			int mid = (L + R) / 2;
			if (pos <= mid)
				return query(pos, i << 1, L, mid);
			else
				return query(pos, i << 1 | 1, mid + 1, R);
		}
	}

	void safe_modify(int l, int r, ll val)
	{
		if (l <= r)
			modify(l, r, val);
		else
		{
			modify(l, n - 1, val);
			modify(0, r, val);
		}
	}
} open, conceal;

const ll inf = 1e9;

void init(int k, vector<int> r)
{
	n = r.size();
	seg.init();
	zero.init();
	open.init();
	conceal.init();
	for (int i = 0; i < n; i++)
	{
		r[i] = k - 1 - r[i];
		seg.modify(i, i, r[i]);
		zero.modify(i, i, r[i]);
	}
	for (int it = 1; it <= n; it++)
	{
		{
			auto [v, p] = zero.query(0, n - 1);
			while (v == 0)
			{
				seg.safe_modify((p + 1) % n, (p + k - 1) % n, inf);
				zero.modify(p, p, inf);
				out[p] = open.query(p);
				tie(v, p) = zero.query(0, n - 1);
			}
		}
		int cur = seg.query(0, n - 1).S;
		in[cur] = conceal.query(cur);
		// cerr << cur << '\n';
		seg.modify(cur, cur, inf);
		seg.safe_modify((cur + 1) % n, (cur + k - 1) % n, -inf);
		zero.safe_modify((cur - k + 1 + n) % n, cur, -1);
		seg.safe_modify((cur - k + 1 + n) % n, cur, -1);
		conceal.safe_modify((cur + 1) % n, (cur + k - 1) % n, cur);
		open.safe_modify((cur - k + 1 + n) % n, cur, cur);
		assert(order[cur] == 0);
		order[cur] = it;
	}
	for (int i = 0; i < n; i++)
		cerr << order[i] << ' ' << in[i] << ' ' << out[i] << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		int u = order[i];
		reachability[u][u] = 1;
		if (in[u] >= 0)
			reachability[in[u]] |= reachability[u];
		if (out[u] >= 0)
			reachability[out[u]] |= reachability[u];
	}
	return;
}

int compare_plants(int x, int y)
{
	if (reachability[x][y])
		return -1;
	if (reachability[y][x])
		return 1;
	return 0;
}
