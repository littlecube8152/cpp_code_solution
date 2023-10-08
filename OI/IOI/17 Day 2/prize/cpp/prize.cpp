#include "prize.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

namespace
{
	int n, bad = 0, q = 0;
	vector<int> res[200005];
};

pii how(int k)
{
	if (k == -1)
		return pii(0, bad);
	else if (k == n)
		return pii(bad, 0);
	if (res[k].size() == 0)
		res[k] = ask(k), q++;
	return pii(res[k][0], res[k][1]);
}

vector<int> large;

void update(int l)
{
	large.emplace_back(l);
}

void count(vector<int> v, int l, int r)
{
	int rem = how(r).F - how(l).F - ((r - l - 1) - (int)v.size());
	if (rem == 0)
		return;
	if (rem == v.size())
	{
		for (auto i : v)
			large.emplace_back(i);
		return;
	}

	bool proceed = 1;
	int cur;
	while (proceed)
	{
		if (v.empty())
			return;
		int k = v.size() / 2;
		cur = v[k];
		if (how(cur).F + how(cur).S < bad)
		{
			update(v[k]);
			v.erase(v.begin() + k);
		}
		else
			proceed = 0;
	}
	int k = v.size() / 2;
	vector<int> left(v.begin(), v.begin() + k),
		right(v.begin() + k + 1, v.end());

	count(left, l, cur);
	count(right, cur, r);
}

vector<int> cnt;

void count(int l, int r, int rem)
{
	if (rem <= 0)
		return;
	rem--;
	int m = (l + r) / 2, lrem = rem / 2;
	bad = max(bad, how(m).F + how(m).S);
	cnt.emplace_back(m);
	count(l, m - 1, lrem);
	count(m + 1, r, rem - lrem);
}

int find_best(int n)
{
	::n = n;
	if (n <= 5000)
		for (int i = 0; i < n; i++)
			if (how(i).F + how(i).S == 0)
				return i;

	count(0, n - 1, 480);
	assert(bad <= 480);
	int l = -1, last = 0;
	vector<int> v;
	sort(cnt.begin(), cnt.end());
	cnt.emplace_back(n);
	for (int r : cnt)
	{
		for (int i = last; i < r; i++)
			v.emplace_back(i);
		last = r + 1;
		if (how(r).F + how(r).S < bad)
			update(r);
		else
		{
			count(v, l, r);
			l = r;
			v.clear();
		}
	}

	for (int i : large)
		cerr << i << ' ';
	cerr << '\n';

	if(q > 4302)
		return -1;
	for (int i : large)
		if (how(i) == pii(0, 0))
			return i;
	return 0;
}
