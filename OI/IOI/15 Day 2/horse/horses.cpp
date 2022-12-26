#include "horses.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1'000'000'007;
ll N, x[500005], y[500005];
struct node
{
	ll L = 0, Lmod = 0, R = 0, Rmod = 0, price = 0;
};

ll mul(ll a, ll b)
{
	return min(mod, a * b);
}

node merge(node n, node m)
{
	node ans;
	if (n.price <= min(mod, n.R * m.L) * m.price)
		ans = node{mul(mul(n.L, n.R), m.L),
				   n.Lmod * n.Rmod % mod * m.Lmod % mod,
				   m.R,
				   m.Rmod,
				   m.price};
	else
		ans = node{n.L,
				   n.Lmod,
				   mul(n.R, mul(m.L, m.R)),
				   n.Rmod * m.Lmod % mod * m.Rmod % mod,
				   n.price};
	return ans;
}

node seg[2000005];

void build(ll X[], ll Y[], int i = 1, int L = 0, int R = N - 1)
{
	if (L == R)
		seg[i] = node{X[L], X[L], 1, 1, Y[L]};
	else
	{
		int mid = (L + R) / 2;
		build(X, Y, i << 1, L, mid);
		build(X, Y, i << 1 | 1, mid + 1, R);
		seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
	}
}

void modify(int pos, ll X, ll Y, int i = 1, int L = 0, int R = N - 1)
{
	if (L == R)
		seg[i] = node{X, X, 1, 1, Y};
	else
	{
		int mid = (L + R) / 2;
		if (pos <= mid)
			modify(pos, X, Y, i << 1, L, mid);
		else
			modify(pos, X, Y, i << 1 | 1, mid + 1, R);
		seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
	}
}

int init(int n, int X[], int Y[])
{
	N = n;
	for(int i = 0; i < N; i++)
		x[i] = X[i], y[i] = Y[i];
	build(x, y);
	return seg[1].Lmod * seg[1].price % mod;
}

int updateX(int pos, int val)
{
	x[pos] = val;
	modify(pos, x[pos], y[pos]);
	return seg[1].Lmod * seg[1].price % mod;
}

int updateY(int pos, int val)
{
	y[pos] = val;
	modify(pos, x[pos], y[pos]);
	return seg[1].Lmod * seg[1].price % mod;
}
