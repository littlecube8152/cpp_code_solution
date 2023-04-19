#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, G;
double pref[15][15][100005], suf[15][15][100005], cost[15][1 << 15], dp[1 << 15];
vector<int> place[15];
string s;


double sum(int i, int mask, int mid)
{
	double res = 0, pre = 0, su = 0;
	for (int j = 0; j < G; j++)
		if (mask & (1 << j))
			res += pref[i][j][mid] + suf[i][j][mid + 1];

	res += pref[i][i][mid] + suf[i][i][mid + 1];

	return res;
}

signed main()
{
	cin >> s;
	N = s.size();
	s = " " + s + " ";
	for (int i = 1; i <= N; i++)
		G = max(G, s[i] - 'A' + 1);
	for (int i = 0; i < G; i++)
		place[i].emplace_back(0);
	for (int i = 1; i <= N; i++)
		place[s[i] - 'A'].emplace_back(i);
	for (int i = 0; i < G; i++)
	{
		int acc[15] = {};
		for (int j = 1; j <= N; j++)
		{
			if (s[j] - 'A' == i)
				for (int k = 0; k < G; k++)
					pref[i][k][j] += (i == k ? 0.5 * acc[k] : 1.0 * acc[k]);
			acc[s[j] - 'A']++;
			for (int k = 0; k < G; k++)
				pref[i][k][j] += pref[i][k][j - 1];
		}
	}
	for (int i = 0; i < G; i++)
	{
		int acc[15] = {};
		for (int j = N; j >= 1; j--)
		{
			if (s[j] - 'A' == i)
				for (int k = 0; k < G; k++)
					suf[i][k][j] += (i == k ? 0.5 * acc[k] : 1.0 * acc[k]);
			acc[s[j] - 'A']++;
			for (int k = 0; k < G; k++)
				suf[i][k][j] += suf[i][k][j + 1];
		}
	}
	for (int i = 0; i < G; i++)
		for (int mask = 0; mask < (1 << G); mask++)
			if ((mask & (1 << i)) == 0)
			{
				cost[i][mask] = 1e10;
				int L = 0, R = place[i].size() - 1;
				while (R > L)
				{
					int mid = (L + R) / 2;
					if (sum(i, mask, place[i][mid]) > sum(i, mask, place[i][mid + 1]))
						L = mid + 1;
					else
						R = mid;
				}
				cost[i][mask] = min(cost[i][mask], sum(i, mask, place[i][L]));
			}

	for (int mask = 0; mask < (1 << G); mask++)
	{
		dp[mask] = (mask == 0 ? 0.0 : 1e10);
		for (int i = 0; i < G; i++)
			if (mask & (1 << i))
				dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + cost[i][mask ^ (1 << i)]);
	}
	cout << fixed << setprecision(10) << dp[(1 << G) - 1] << '\n';
}
