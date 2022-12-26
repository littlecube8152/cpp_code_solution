#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1000000007;

ll n, p[1000006], vis[1000006], ans, fac[1000006], ifac[1000006];
vector<int> v;

int dfs(int i)
{
	if(!vis[p[i]])
	{
		vis[p[i]] = 1;
		return dfs(p[i]) + 1;
	}
	return 0;
}

ll inv(ll b)
{
	ll a = 1, p = mod - 2;
	while(p)
	{
		if(p & 1)
			a = a * b % mod;
		b = b * b % mod;
		p >>= 1;
	}
	return a;
}

ll C(int n, int m)
{
	return (fac[n] * ifac[m] % mod) * ifac[n - m] % mod;
}

ll calc(int n, int a, int b)
{
	ll res = 0;
	for(int k = 0; k <= n - a - b; k++)
		res = (res + (k + 1) * C(n - k - 1, a + b - 1)) % mod;
	res = (res * fac[a] % mod) * fac[b] % mod;
	res = res * fac[n - a - b] % mod;
	return res;
}

signed main()
{
	fac[0] = ifac[0] = 1;
	cin >> n;
	for(int i = 1; i <= n + 5; i++)
	{	
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = inv(fac[i]);
	}

	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			v.emplace_back(dfs(i));
	for(int p : v)
	{
		if(p == 1)
		{	
			ans = (ans + fac[n] * n) % mod;
			continue;
		}
		else if(p == 2)
		{
			ans = (ans + 2 * fac[n] * n) % mod;
		   	for(int i = 1; i < n; i++)
				ans = (ans - 2 * (n - i) * i * fac[n - 2]) % mod;
			ans = (ans + mod) % mod;
			continue;
		}
		ans = (ans + (fac[n] * p % mod) * p) % mod;
		if(p % 2 == 0)
			ans = (ans + 2 * calc(n, p / 2, p / 2)) % mod;
		if(p >= 3)
			ans = (ans - (4 * p * inv(3) % mod) * calc(n, 0, 3)) % mod;
		ans = (ans + mod) % mod;
		// cout << p << ' ' << calc(n, p / 2, p / 2) << ' ' << (4 * p * inv(3) % mod) * calc(n, 0, 3) % mod << '\n';;
	}
	cout << ans << '\n';
}
