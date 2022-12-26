#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll H, W, A[1005], B[1005], dp[1005][1005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> H >> W;
	for(int i = 1; i <= H; i++)
		cin >> A[i];
	for(int i = 1; i <= W; i++)
		cin >> B[i];
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
		{
			dp[i][j] = (i + j == 2 ? 0 : 1e18);
			if(j > 1)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i]);
			if(i > 1)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + B[j]);
			cout << dp[i][j] << " \n"[j == W];
		}
	cout << dp[H][W];
}
