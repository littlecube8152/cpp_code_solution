#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, dp[1005][1005], T;
string s;
signed main()
{
	cin >> T;
	getline(cin, s);
	while(T--)
	{
		getline(cin, s);
		N = s.size();
		int ans = 0;
		for(int i = 0; i <= N + 1; i++)
			for(int j = 0; j <= N + 1; j++)
				dp[i][j] = 0;
		for(int i = 0; i <= N; i++)
			for(int j = N + 1; j >= i; j--)
			{
				if(i > 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if(j <= N)
					dp[i][j] = max(dp[i][j], dp[i][j + 1]);
				if(i > 0 && j <= N)
					dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + (s[i - 1] != s[j - 1] ? 0 : (1 + (i != j))));
			}
		for(int i = 0; i <= N; i++)
			ans = max({ans, dp[i][i], dp[i][i + 1]});
		cout << ans << '\n';
	}
}
