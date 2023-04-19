#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1'000'000'007;
ll N, M, dp[500005][26], pre[500005][2], ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<pii> v[2];
	for(int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a < b)
			v[0].emplace_back(pii(a, b));
		else 
			v[1].emplace_back(pii(b, a));
	}

	for(int t = 0; t <= 1; t++)
	{
		sort(v[t].begin(), v[t].end(), [](pii p1, pii p2){ return p1.S < p2.S; });
		
		multiset<int, greater<int>> st;
		
		st.insert(0);

		for(int i = N; i >= 1; i--)
		{
			while(!v[t].empty() && v[t].back().S >= i)
			{
				st.insert(v[t].back().F);
				v[t].pop_back();
			}
			pre[i][t] = *st.upper_bound(i);
		}
	}
	

	for(int i = 0; i < 26; i++)
		dp[1][i] = 1;

	for(int i = 2; i <= N; i++)
		for(int j = 0; j < 26; j++)
		{	
			for(int k = 0; k < 26; k++)
			{
				int mx = max(pre[i][0], pre[i][1]);
				if(pre[i][0] <= pre[i][1])
				{
					if(j > k)
						dp[i][j] = (dp[i][j] + dp[i - 1][k] - dp[mx][k] + mod) % mod;
					if(j < k)
						dp[i][j] = (dp[i][j] + dp[i - 1][k] - dp[pre[i][0]][k] + mod) % mod;
				}
				else
				{
					if(j > k)
						dp[i][j] = (dp[i][j] + dp[i - 1][k] - dp[pre[i][1]][k] + mod) % mod;
					if(j < k) 
						dp[i][j] = (dp[i][j] + dp[i - 1][k] - dp[mx][k] + mod) % mod;
				}
			}
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
		}
	
	for(int j = 0; j < 26; j++)
		ans = (ans + dp[N][j]) % mod;
	cout << ans << '\n';
}
