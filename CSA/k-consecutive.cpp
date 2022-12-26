/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, M, dp[5005][5005][2], ans;

signed main()
{
    fast;
	cin >> N >> M;
	dp[0][0][0] = 1;
	for(int j = 1; j <= N; j++)
	{
		for(int i = 1; i < N; i++)
		{
			dp[i][j - 1][0] = (dp[i][j - 1][0] + dp[i - 1][j - 1][0]) % MOD;
			dp[i][j - 1][1] = (dp[i][j - 1][1] + dp[i - 1][j - 1][1]) % MOD;
		}
		for(int i = 1; i <= N; i++)
		{	
			dp[i][j][0] = ((dp[i - 1][j - 1][1] - (i <= M ? 0 : dp[i - M - 1][j - 1][1]) + dp[i - 1][j - 1][0] - (i <= M ? 0 : dp[i - M - 1][j - 1][0]) + 2 * MOD) * (j - 1)) % MOD;
			dp[i][j][1] = (dp[i - 1][j - 1][0] - (i <= M ? 0 : dp[i - M - 1][j - 1][0]) + MOD) % MOD;
		}	
	}
	for(int i = 1; i <= N; i++)
		ans = (ans + dp[N][i][0] + dp[N][i][1]) % MOD;
	cout << ans << '\n';
}

