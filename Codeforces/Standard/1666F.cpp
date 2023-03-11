#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define x first
#define S second
#define y second
using namespace std;

ll n, a[5005], p[5005], dp[5005][2505], tr[5005][2505], fac[5005];
const ll mod = 998244353;

ll fpow(ll b, ll p = mod - 2)
{
	ll a = 1;
	while(p)
	{
		if(p & 1)
			a = a * b % mod;
		b = b * b % mod;
		p >>= 1; 
	}
	return a;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1, j = 0; i <= n; i++)
	{
		while(a[j + 1] < a[i])
			j++;
		p[i] = j;
	}
	ll div = 1;
	for(int i = 1, j = 1; i <= n; i++)
	{
		if(a[i] != a[i - 1])
			j = 1;
		else 
			j++;
		div = div * j % mod;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n / 2; j++)
			dp[i][j] = tr[i][j] = 0;
			
	for (int i = 1; i <= n; i++)
		if(p[i])
			dp[i][1] = p[i];

	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= n / 2; j++)
		{
			dp[i][j] = (dp[i][j] + tr[p[i]][j - 1]) % mod;
			tr[i][j] = (tr[i - 1][j] + dp[i][j] * max(0LL, p[i] - 2 * j + 1));
		}
	cout << (dp[n][n / 2] * fpow(div) % mod) << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();

} 

