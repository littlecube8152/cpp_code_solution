#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int mod = 1e9 + 7;
int T, N, A, B, dp[2005][2005][2];
char a[2005], b[2005];

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> N;
		A = B = N;
		for(int i = 1; i <= A; i++)
		{
			cin >> a[i];
			if(a[i] == '1')
				i--, A--;
		}
		for(int i = 1; i <= B; i++)
		{
			cin >> b[i];
			if(b[i] == '1')
				i--, B--;
		}
		for(int i = 0; i <= A; i++)
			for(int j = 0; j <= B; j++)
				dp[i][j][0] = dp[i][j][1] = 0;
	
		for(int i = 1; i <= A; i++)
			dp[i][0][(a[i] == '+')] = 1;
		for(int i = 1; i <= B; i++)
			dp[0][i][(b[i] == '+')] = 1;
		dp[0][0][0] = 1;
		for(int i = 1; i <= A; i++)
			for(int j = 1; j <= B; j++)
			{
							
				if(a[i] == '+' || b[j] == '+')
				{
					int ii = i, jj = j;
					while(b[jj] == '+')
						jj--;
					while(a[ii] == '+')
						ii--;
					for (int k = ii; k <= i; k++)
						if(i - k + j - jj)
							dp[i][j][1] = (dp[i][j][1] + dp[k][jj][0]) % mod;
					for (int k = jj + 1; k <= j; k++)
						if(i - ii + j - k)
							dp[i][j][1] = (dp[i][j][1] + dp[ii][k][0]) % mod;		
				}
				if(a[i] != '+' || b[j] != '+')
				{
					int ii = i, iz = 0, jj = j, jz = 0;
					while('0' <= a[ii] && a[ii] <= '9')
					{
						if(a[ii] == '0')
							iz = max(iz, ii);
						ii--;
					}
					while('0' <= b[jj] && b[jj] <= '9')
					{
						if(b[jj] == '0')
							jz = max(jz, jj);
						jj--;
					}
					for (int k = ii; k <= i; k++)
						if(i - k + j - jj && k >= iz && !jz)
							dp[i][j][0] = (dp[i][j][0] + dp[k][jj][1]) % mod;
					for (int k = jj + 1; k <= j; k++)
						if(i - ii + j - k && k >= jz && !iz)
							dp[i][j][0] = (dp[i][j][0] + dp[ii][k][1]) % mod;		
					if(iz || jz)
						dp[i][j][0] = (dp[i][j][0] + 1) % mod;
				}

			}
		cout << (dp[A][B][0] + dp[A][B][1]) % mod << '\n';
	}
}
