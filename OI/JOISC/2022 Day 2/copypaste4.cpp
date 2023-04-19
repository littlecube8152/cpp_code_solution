#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll base = 29, mod = 462'779'347'772'851;

int N;
char c[2505];
ll A, B, C, dp[2505][2505], h[2505][2505], nxt[2505][2505];

signed main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> c[i];
	cin >> A >> B >> C;
	for(int i = 1; i <= N; i++)
		for(int j = i; j <= N; j++)
		{
			dp[i][j] = A * (j - i + 1);
			h[i][j] = (h[i][j - 1] * base + c[j] - 'a') % mod;
		}
	for(int l = 1; l <= N; l++)
	{	
		map<ll, int> mp;
		for(int i = N - l + 1; i >= 1; i--)
			if(i + 2 * l - 1 <= N)
			{
				mp[h[i + l][i + 2 * l - 1]] = i + l;
				nxt[i][i + l - 1] = mp[h[i][i + l - 1]];
			    //	cout << "[" << i << ", " << i + l - 1 << "] -> [" << nxt[i][i + l - 1] << "]\n";
			}
	}		

	for(int i = N; i >= 1; i--)
		for(int k = i; k <= N; k++)
		{	
			dp[i][k] = min({dp[i][k], dp[i + 1][k] + A, dp[i][k - 1] + A});
			ll base = dp[i][k] + B, j = nxt[i][k], t = 2;

			for(; j != 0; j = nxt[j][j + k - i])
			{
				dp[i][j + k - i] = min(dp[i][j + k - i], base + t * C + (j + k - i - i + 1 - t * (k - i + 1)) * A);
				t++;
			}
		}

	/* for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if(j < i) cout << "- ";
			else cout << dp[i][j] << " \n"[N == j];
	*/
	cout << dp[1][N] << '\n';
}
