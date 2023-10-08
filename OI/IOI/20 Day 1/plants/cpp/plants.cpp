#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

namespace
{
	int n, k, order[200005], out[200005], in[200005];
	ll l[200005][20], r[200005][20];
}

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
			if (seg[i] != -1)
			{
				seg[i << 1] = seg[i << 1 | 1] = seg[i];
				seg[i] = -1;
			}
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
	::k = k;
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
		// cerr << cur << "->" << in[cur] << ' ' << out[cur] << '\n';
		seg.modify(cur, cur, inf);
		seg.safe_modify((cur + 1) % n, (cur + k - 1) % n, -inf);
		zero.safe_modify((cur - k + 1 + n) % n, cur, -1);
		seg.safe_modify((cur - k + 1 + n) % n, cur, -1);
		conceal.safe_modify((cur + 1) % n, (cur + k - 1) % n, cur);
		open.safe_modify((cur - k + 1 + n) % n, cur, cur);
		assert(order[cur] == 0);
		order[cur] = it;
	}

	vector<int> ord(n);
	for (int i = 0; i < n; i++)
		ord[order[i] - 1] = i;
	for (int i = 0; i < n; i++)
	{
		int u = ord[i];
		if (in[u] >= 0)
			l[u][0] = (u - in[u] + n) % n;
		else
			l[u][0] = 0;
		if (out[u] >= 0)
			::r[u][0] = (out[u] - u + n) % n;
		else
			::r[u][0] = 0;
	}
	for (int p = 0; p + 1 < 20; p++)
		for (int i = 0; i < n; i++)
		{
			l[i][p + 1] = l[i][p] + l[((i - l[i][p]) % n + n) % n][p];
			::r[i][p + 1] = ::r[i][p] + ::r[(i + ::r[i][p]) % n][p];
		}
	// for (int i = 0; i < n; i++)
	// 	cerr << in[i] << ' ' << l[i] << ' ' << out[i] << ' ' << ::r[i] << '\n';
}

bool reach(int x, int y)
{
	// check left
	int u = x, v = y;
	if (u > v)
		u -= n;
	for (int p = 19; p >= 0; p--)
		if (u <= v - l[(v + n) % n][p])
			v = v - l[(v + n) % n][p];
	if (abs(u - v) < k && order[(u + n) % n] <= order[(v + n) % n])
		return 1;
	u = x, v = y;
	if (u < v)
		u += n;
	for (int p = 19; p >= 0; p--)
		if (v + r[v % n][p] <= u)
			v = v + r[v % n][p];
	if (abs(u - v) < k)
		return order[u % n] <= order[v % n];
	return 0;
}

int compare_plants(int x, int y)
{
	if (reach(x, y))
		return -1;
	if (reach(y, x))
		return 1;
	return 0;
}
