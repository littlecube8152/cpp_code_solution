#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const ll mod = 998'244'353;

int n, m;
ll up[1005][1005], lef[1005][1005], ans = 2;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> lef[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> up[i][j];



	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
		{
			lef[i][j] = (lef[i][j + 1] + lef[i][j]) % mod;
			up[i][j] = (up[i + 1][j] + up[i][j]) % mod;
			ans = (ans + (1 - up[i][j]) * (1 - lef[i][j]) % mod * lef[i + 1][j] % mod * up[i][j + 1]) % mod;
		}

	

	cout << (ans + mod) % mod << '\n';
}




