#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int n, out[200005], in[200005], order[200005][2];

struct segTree
{
	pll seg[800005];
	ll lazy[800005];

	void init(int sgn, int i = 1, int L = 0, int R = n - 1)
	{
		seg[i] = pll(0, (sgn == 1 ? L : -R));
		lazy[i] = 0;
		if (L == R)
			return;
		int mid = (L + R) / 2;
		init(sgn, i << 1, L, mid);
		init(sgn, i << 1 | 1, mid + 1, R);
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

const ll inf = 1e9;

void init(int k, vector<int> r)
{
	n = r.size();
	for (int i = 0; i < n; i++)
		r[i] = k - 1 - r[i];
	for (int t = 0, s = 1; t <= 1; t++, s = -1)
	{
		seg.init(s);
		zero.init(s);
		for (int i = 0; i < n; i++)
		{
			seg.modify(i, i, r[i]);
			zero.modify(i, i, r[i]);
		}
		for (int it = 1; it <= n; it++)
		{
			{
				auto [v, p] = zero.query(0, n - 1);
				while (v == 0)
				{
					p = s * p;
					seg.safe_modify((p + 1) % n, (p + k - 1) % n, inf);
					zero.modify(p, p, inf);
					tie(v, p) = zero.query(0, n - 1);
				}
			}
			int cur = seg.query(0, n - 1).S * s;
			seg.modify(cur, cur, inf);
			seg.safe_modify((cur + 1) % n, (cur + k - 1) % n, -inf);
			zero.safe_modify((cur - k + 1 + n) % n, cur, -1);
			seg.safe_modify((cur - k + 1 + n) % n, cur, -1);
			assert(order[cur][t] == 0);
			order[cur][t] = it;
		}
	}
	return;
}

int compare_plants(int x, int y)
{
	if (order[x][0] < order[y][0] && order[x][1] < order[y][1])
		return -1;
	if (order[x][0] > order[y][0] && order[x][1] > order[y][1])
		return 1;
	return 0;
}
