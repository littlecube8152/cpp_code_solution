#include "teams.h"
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, root[500005];
vector<int> v[500005];
struct node
{
	int t = 0, l = -1, r = -1, val = 0;
};
vector<node> pSeg(1);

int copy_node(int i, int t)
{
	int j = pSeg.size();
	pSeg.emplace_back(pSeg[i]);
	pSeg[j].t = t;
	return j;
}

void build(int i, int L = 1, int R = N)
{
	if (L != R)
	{
		int mid = (L + R) / 2;
		pSeg[i].l = pSeg.size();
		pSeg.emplace_back(node{});
		build(pSeg[i].l, L, mid);
		pSeg[i].r = pSeg.size();
		pSeg.emplace_back(node{});
		build(pSeg[i].r, mid + 1, R);
	}
}

void modify(int pos, int i, int L = 1, int R = N)
{
	if (L != R)
	{
		int mid = (L + R) / 2;
		if (pos <= mid)
		{
			if (pSeg[pSeg[i].l].t < pSeg[i].t)
				pSeg[i].l = copy_node(pSeg[i].l, pSeg[i].t);
			modify(pos, pSeg[i].l, L, mid);
		}
		else
		{
			if (pSeg[pSeg[i].r].t < pSeg[i].t)
				pSeg[i].r = copy_node(pSeg[i].r, pSeg[i].t);
			modify(pos, pSeg[i].r, mid + 1, R);
		}
		pSeg[i].val = pSeg[pSeg[i].l].val + pSeg[pSeg[i].r].val;
	}
	else
		pSeg[i].val++;
}

int query(int qL, int qR, int i, int L = 1, int R = N)
{
	if (qL <= L && R <= qR)
		return pSeg[i].val;
	else if (R < qL || qR < L)
		return 0;
	else
	{
		int mid = (L + R) / 2;
		return query(qL, qR, pSeg[i].l, L, mid) + query(qL, qR, pSeg[i].r, mid + 1, R);
	}
}

int search(int dpi, int dpj, int minL, int pi, int pj, int L = 1, int R = N)
{
	int mid = (L + R) / 2;
	if(L == R)
		return L;
	if(mid < minL || dpi - pSeg[pSeg[pi].r].val < dpj - pSeg[pSeg[pj].r].val)
		return search(dpi, dpj, minL, pSeg[pi].r, pSeg[pj].r, mid + 1, R);
	else 
		return search(dpi - pSeg[pSeg[pi].r].val, dpj - pSeg[pSeg[pj].r].val, minL, pSeg[pi].l, pSeg[pj].l, L, mid);
	// dp[i] - query(mid + 1, N, root[K[i]]) < dp[j] - query(mid + 1, N, root[K[j]]) => [mid + 1, R];
	// else                                                                      => [L, mid]	;
}

void init(int n, int A[], int B[])
{
	N = n;
	for (int i = 0; i < N; i++)
		v[A[i]].emplace_back(B[i]);
	root[0] = 0;
	build(0);
	for (int i = 1; i <= N; i++)
	{
		root[i] = copy_node(root[i - 1], i);
		for (int j : v[i])
			modify(j, root[i]);
	}
}

//                                L              R
// dp[i] = min dp[j] + n([K[j] + 1, K[i]] x [K[i], N]) - cnt
// Segment tree should maintain R, and binary search cost through two version of L (K[i] and K[j])
int can(int M, int k[])
{
	sort(k, k + M);
	vector<int> K(1, 0), cnt(1, 0);
	for (int i = 0; i < M; i++)
		if (k[i] == K.back())
			cnt.back() += k[i];
		else
		{
			K.emplace_back(k[i]);
			cnt.emplace_back(k[i]);
		}
	M = (int)K.size() - 1;
	vector<int> dp(K.size(), 0);
	vector<pii> mono;
	mono.emplace_back(pii(0, N + 1));
	for (int i = 1; i <= M; i++)
	{
		while(mono.back().S < K[i])
			mono.pop_back();
		int j = mono.back().F;
		dp[i] = dp[j] + query(K[i], N, root[K[i]]) - query(K[i], N, root[K[j]]) - cnt[i];
		while(!mono.empty() && search(dp[i], dp[j], K[i], root[K[i]], root[K[j]]) >= mono.back().S)	
		{
			mono.pop_back();
			j = mono.back().F;
		}
		mono.emplace_back(pii(i, search(dp[i], dp[j], K[i], root[K[i]], root[K[j]])));
		if (dp[i] < 0)
			return 0;
	}
	return 1;
}
