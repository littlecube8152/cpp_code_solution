#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1000000007;

ll n, p[1000006], vis[18], ans, dp[1 << 18], cur[1 << 18], t[1 << 18];

void dfs(int i)
{
	if(!vis[p[i]])
	{
		vis[p[i]] = vis[i];
		dfs(p[i]);	
	}
}

bool ithbit(int mask, int i)
{
	return (mask >> i) & 1;
}


signed main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{	
		cin >> p[i];
		p[i]--;
	}

	for(int i = 0; i < n; i++)
		if(!vis[i])
		{	
			vis[i] = i + 1;
			dfs(i);
			
		}
	
	if(n <= 18)
	{
		t[(1 << n) - 1] = 1;
		for(int i = 1; i <= n; i++)
			t[(1 << n) - 1] *= i;

		for(int mask = (1 << n) - 1; mask >= 0; mask--)
		{
			int rem[20] = {}, edge = 0;
			for(int i = 0; i < n; i++)
				rem[vis[i]]++;
			for(int i = 0; i < n; i++)
				if(ithbit(mask, i) ^ ithbit(mask, p[i]))
					rem[vis[i]] = max(1, rem[vis[i]] - 1);
			for(int i = 0; i <= n; i++)
				edge += rem[i];
			cur[mask] = max(1, edge);
		}

		cur[(1 << n) - 1] = 0;

		for(int mask = (1 << n) - 1; mask >= 0; mask--)
		{	
			ans = (ans + t[mask] * cur[mask]) % mod;
			if(mask != 0)
			for(int i = 0; i < n; i++)
				if(ithbit(mask, i)) 
					t[mask ^ (1 << i)] = (t[mask] / __builtin_popcount(mask) + t[mask ^ (1 << i)]);
			// bitset<18> b = mask;
			// cout << b << ' ' << dp[mask] << ' ' << t[mask] << ' ' << cur[mask] << '\n';
		}
	}
	
	
	
	cout << ans % mod << '\n';
}
