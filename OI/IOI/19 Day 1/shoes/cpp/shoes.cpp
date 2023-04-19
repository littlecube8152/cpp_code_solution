#include "shoes.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

vector<int> p[100005][2];
int N, bit[2000005], a[200005];

void modify(int pos)
{
	for (int i = pos + 1; i <= 2 * N; i += (i & -i))
		bit[i]++;
}

int query(int pos)
{
	int ans = 0;
	for (int i = pos + 1; i; i -= (i & -i))
		ans += bit[i];
	return ans;
}

ll count_swaps(vector<int> s)
{
	N = s.size() / 2;
	ll ans = 0;
	for (int i = 0; i < N * 2; i++)
	{
		if (s[i] < 0)
			p[-s[i]][1].emplace_back(i);
		else
			p[s[i]][0].emplace_back(i);
	}
	for (int i = 0; i < 2 * N; i++)
		a[i] = -1;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < p[i][0].size(); j++)
		{
			if(p[i][1][j] > p[i][0][j])
				ans += 2, swap(p[i][1][j], p[i][0][j]);
			a[p[i][0][j]] = p[i][1][j];
		}
	
	for (int i = 0; i < 2 * N; i++)
	{
		if(a[i] >= 0)
		{
			modify(a[i]);
			int in = query(i) - query(a[i]);
			//cerr << i << ' ' << a[i] << ' ' << in << '\n';
			ans += 4 * in + (i - a[i] - 1 - 2 * in);
		}
	}
	return ans / 2;
}
