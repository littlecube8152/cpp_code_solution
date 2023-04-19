#include "rect.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, in[2500];
ll ans;

ll count_rectangles(vector<vector<int>> a)
{
	N = a.size(), M = a[0].size();
	assert(N <= 3);
	if (N <= 2 || M <= 2)
		return 0;
	for (int i = 1; i < M - 1; i++)
		if (a[0][i] > a[1][i] && a[1][i] < a[2][i])
			in[i] = 1;
	for (int i = 1; i < M - 1; i++)
	{
		int mx = 0;
		for (int j = i; j < M - 1; j++)
		{
			if(!in[j])
				break;
			mx = max(a[1][j], mx);
			ans += (a[1][i - 1] > mx && mx < a[1][j + 1]);
		}
	}
	assert(ans <= M);
	return ans;
}
