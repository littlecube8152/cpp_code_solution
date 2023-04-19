#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1'000'000'007;
ll N, M, dp[205][205][26], A[205][2], B[205][2], sum[205][205][2], ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a < b)
		{	
			A[a][0]++, B[b][0]++;
			for(int j = a; j <= b - 1; j++)
				sum[j][j - a][0]++;
		}
		else 
		{	
			A[b][1]++, B[a][1]++;
			for(int j = b; j <= a - 1; j++)
				sum[j][j - b][1]++;
		}
	}

	for(int i = 1; i <= N; i++)
		for(int j = 0; j < i; j++)
		{
			if(j)
			sum[i][j][0] += sum[i][j - 1][0];
			if(j) sum[i][j][1] += sum[i][j - 1][1];
			cout << i << ' ' << j << ':' << '(' << sum[i][j][0] << ", " << sum[i][j][0] << ")" << " \n"[i == j + 1];
		}
	
	for(int i = 0; i < 26; i++)
		dp[1][0][i] = 1;
	for(int i = 1; i < N; i++)
		for(int j = 0; j < i; j++)
			for(int k = 0; k < 26; k++)
				for(int l = 0; l < 26; l++)
				{
					if(l < k && sum[i][j][1] == 0)
						dp[i + 1][0][l] = (dp[i + 1][0][l] + dp[i][j][k]) % mod;
					if(l == k)
						dp[i + 1][j + 1][l] = (dp[i + 1][j + 1][l] + dp[i][j][k]) % mod;
					if(l > k && sum[i][j][0] == 0)
						dp[i + 1][0][l] = (dp[i + 1][0][l] + dp[i][j][k]) % mod;
				}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 26; j++)
			ans = (ans + dp[N][i][j]) % mod;
	cout << ans << '\n';
}
