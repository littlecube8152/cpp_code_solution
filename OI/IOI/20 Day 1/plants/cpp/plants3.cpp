#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int n;
vector<int> a;

struct segTree
{
	pll seg[800005];
	ll lazy[800005];

	void init(int i = 1, int L = 0, int R = n - 1)
	{
		seg[i].S = L;
		if(L == R)
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
} seg;

void init(int k, vector<int> r)
{
	n = r.size();
	a.resize(n);
	seg.init();
	for (int i = 0; i < n; i++)
		seg.modify(i, i, k - 1 - r[i]);
	for (int i = 0; i < n; i++)
	{
		int j = seg.query(0, n - 1).S;
		// cerr << j << "->";
		if(j - k + 1 < 0)
		{
			auto [v1, p1] = seg.query(j - k + 1 + n, n - 1);
			auto [v2, p2] = seg.query(0, j);
			if(v1 == 0)
				j = p1;
			else 
				j = p2;
		}
		else
		{
			auto [v, p] = seg.query(j - k + 1, j);
			j = p;
		}
		// cerr << j << ' ';
		a[j] = i;
		seg.modify(j, j, 1e9);
		if(j - k + 1 < 0)
		{
			seg.modify(j - k + 1 + n, n - 1, -1);
			seg.modify(0, j, -1);
		}
		else
		{
			seg.modify(j - k + 1, j, -1);
		}
	}
	// cerr << '\n';
	return;
}

int compare_plants(int x, int y)
{

	if (a[x] < a[y])
		return -1;
	return 1;
	return 0;
}
