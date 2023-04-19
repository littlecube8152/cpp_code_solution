#include "rect.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, after[2505][2505], si[2505][2505], sj[2505][2505];
ll ans;

ll count_rectangles(vector<vector<int>> a)
{
	N = a.size(), M = a[0].size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			assert(a[i][j] <= 1);
			if (a[i][j])
				after[i + 1][j + 1] = j + 1;
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			si[i][j] = si[i - 1][j] + a[i - 1][j - 1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			sj[i][j] = sj[i][j - 1] + a[i - 1][j - 1];

	for (int i = 1; i <= N; i++)
		for (int j = M; j >= 1; j--)
			if (after[i][j] == 0)
				after[i][j] = after[i][j + 1];

	for (int i = 1; i < M; i++)
	{
		for (int l = 1; l < N; l++)
		{
			int r = l, j = after[l][i] - 1;
			if(j < i)
				continue;
			while (r + 1 < N && after[r + 1][i] == after[l][i])
				r++;
			//cerr << l << ' ' << r << "  " << i << ' ' << j << '\n';
			// there is only one case: [l, r] x [j, after[l][j] - 1]
			if (sj[r + 1][j] - sj[r + 1][i - 1] == j - i + 1 &&
				sj[l - 1][j] - sj[l - 1][i - 1] == j - i + 1 &&
				si[r][j + 1] - si[l - 1][j + 1] == r - l + 1 &&
				si[r][i - 1] - si[l - 1][i - 1] == r - l + 1)
				ans++;
			l = r;
		}
	}

	return ans;
}
