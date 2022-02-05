#include <iostream>
#include <vector>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int table[280][280];
bool used[280];

int distinct(vector<int> s);

vector<int> gen(int l, int r)
{
	vector<int> v;
	for (int i = l; i <= r; i++)
		v.emplace_back(i);
	return v;
}

int query(int l, int r)
{
	if (l == r)
		return 1;
	if (table[l][r] < 0)
	{
		table[l][r] = distinct(gen(l, r));
		if (table[l][r] == (r - l + 1))
			for (int i = l; i <= r; i++)
				for (int j = i; j <= r; j++)
					table[i][j] = (j - i + 1);
	}
	return table[l][r];
}

vector<pii> solve(int l, int r, int cnt)
{
	if (cnt == 0)
		return vector<pii>{};
	if (l == r)
		return vector<pii>{};
	int lcnt, rcnt, mcnt, mid = (l + r) / 2;
	lcnt = (mid - l + 1) - query(l, mid);
	rcnt = (r - mid) - query(mid + 1, r);
	mcnt = cnt - lcnt - rcnt;
	vector<pii> lans = solve(l, mid, lcnt);
	vector<pii> rans = solve(mid + 1, r, rcnt);
	vector<pii> mans;
	for (int i = l; i <= mid; i++)
	{
		vector<int> v = gen(mid + 1, r);
		v.emplace_back(i);
		if (!used[i] && distinct(v) == query(mid + 1, r))
		{
			int L = mid + 1, R = r;
			while (L < R)
			{
				int M = (L + R) / 2;
				vector<int> u = gen(L, M);
				u.emplace_back(i);
				if (distinct(u) == query(L, M))
					R = M;
				else
					L = M + 1;
			}
			used[i] = 1;
			used[L] = 1;
			mans.emplace_back(make_pair(i, L));
		}
	}
	for (pii p : lans)
		mans.emplace_back(p);
	for (pii p : rans)
		mans.emplace_back(p);
	return mans;
}

vector<pii> train(int n)
{
	n *= 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			table[i][j] = -1;
	int cnt = n / 2;
	return solve(1, n, cnt);
}
