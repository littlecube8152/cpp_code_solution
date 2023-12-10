#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

ll ans, has[60], dp[60][60];

void calc(int n, int k)
{
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{	
			if (j) dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j];
		}
}

signed main()
{
	ll n, k;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	calc(n, k);
	for (int i = 0; i <= n; i++)
		if (0 <= k - i && k - i <= n)
		{
			has[i] = 1;
			has[k - i] = 1;
		}
	if (k % 2 == 0)
		has[k / 2] = 2;
	for (int i = 0; i <= n; i++)
	{
		ll cnt = (dp[n][i] + ((n % 2 == 0 && i % 2 == 1) ? 0LL : dp[n / 2][i / 2])) / 2;
		ans += has[i] * cnt;
	}
	cout << ans << '\n';
}

