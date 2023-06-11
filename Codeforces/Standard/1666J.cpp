#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define x first
#define S second
#define y second
using namespace std;

ll n, c[205][205], dp[205][205], head[205][205], p[205];
ll cost(int x1, int x2, int y1, int y2)
{
	return c[x2][y2] - c[x1 - 1][y2] - c[x2][y1 - 1] + c[x1 - 1][y1 - 1];
}

void solve(int l, int r, int h)
{
	p[head[l][r]] = h;
	if(l == r)
		return;
	h = head[l][r];
	if (h != l)
		solve(l, h - 1, h);
	if (h != r)
		solve(h + 1, r, h);
}

signed main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c[i][j]; 
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= n + 1; j++)
			c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
			
	for(int i = 1; i <= n; i++)
		head[i][i] = i;
		
	for(int l = 2; l <= n; l++)
		for(int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			dp[i][j] = 1e18;
			for(int k = i; k <= j; k++)
			{
				ll nxt = dp[i][k - 1] + dp[k + 1][j] + cost(i, k, k + 1, j) + cost(k, j, i, k - 1) + cost(1, i - 1, i, j) + cost(j + 1, n, i, j) - cost(1, i - 1, k, k) - cost(j + 1, n, k, k);
				if(nxt < dp[i][j])
					dp[i][j] = nxt, head[i][j] = k;
			}
		}
	solve(1, n, 0);
	for(int i = 1; i <= n; i++)
		cout << p[i] << " \n"[i == n];
} 

