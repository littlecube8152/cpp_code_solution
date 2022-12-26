#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll M, L, a[605], ans, b[605], dp[100005];

void upd(int count, int v, int w)
{
//	cout << count << "s of " << v << " weighted " << w << '\n';	

	vector<int> cnt;
	for(int j = 1; count >= j; j *= 2)
	{
		cnt.emplace_back(j);
		count -= j;
	}
	cnt.emplace_back(count);
	for(int j : cnt)
		if(v > 0)
			for(int k = M * M; k >= v * j; k--)		
				dp[k] = min(dp[k - v * j] + j * w, dp[k]);
		else if(v < 0)
			for(int k = 0; k <= M * M + v * j; k++)
				dp[k] = min(dp[k - v * j] + j * w, dp[k]);
	//for(int i = 0; i <= M * M; i++)
	//	cout << dp[i] << " \n"[i == M * M];
}


signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	cin >> M >> L;
	for(int i = 1; i <= 2 * M + 1; i++)
	   cin >> a[i];
	if(L < 0)
	{
		L = -L;
		for(int i = 1; i <= M; i++)
			swap(a[i], a[2 * M + 2 - i]);
	}	
	for(int i = 1; i <= M; i++)
	{		
		L += a[M + 1 - i] * i, ans += a[M + 1 - i];
		swap(a[M + 1 - i], b[M + 1 - i]);
	}
	//cout << L << '\n';
	
	ans += a[M + 1];
	swap(a[M + 1], b[M + 1]);
	
	for(int i = 1; i <= M; i++)
		if(i * a[M + 1 + i] <= L)
		{
			ans += a[M + 1 + i];
			L -= i * a[M + 1 + i];
			b[M + 1 + i] = min(M, a[M + 1 + i]);
			a[M + 1 + i] = 0;
		}
		else
		{
			ans += L / i;
			b[i + M + 1] = min(M, L / i);
			a[i + M + 1] = min(M, a[i + M + 1] - L / i);
			L %= i;
		}
	for(int i = M; i >= 1; i--)
		if(i * b[M + 1 - i] <= L)
		{
			ans -= b[M + 1 - i];
			L -= i * b[M + 1 - i];
			a[M + 1 - i] = min(M, b[M + 1 - i]);
			b[M + 1 - i] = 0;
		}
		else
		{
			ans -= L / i;
			a[M + 1 - i] = min(M, L / i);
			b[M + 1 - i] = min(M, b[M + 1 - i] - L / i);
			L %= i;
		}
		
	if(L > M)
	{
		cout << "impossible\n";
		return 0;
	}

	//for(int i = 1; i <= M * 2 + 1; i++)
	//	cerr << a[i] << " \n"[i == 2 * M + 1];
	//for(int i = 1; i <= M * 2 + 1; i++)
	//	cerr << b[i] << " \n"[i == 2 * M + 1];
	//cerr << ans << " " << L << '\n';

	for(int i = 0; i <= M * M; i++)
		dp[i] = (i == 0 ? 0 : 1e18);

	for(int i = 1; i <= M; i++)
		upd(a[i + M + 1], i, -1);
	for(int i = 1; i <= M; i++)
		upd(b[M + 1 - i], i, 1);
	for(int i = 1; i <= M; i++)
		upd(b[M + i + 1], -i, 1);
	for(int i = 1; i <= M; i++)
		upd(a[M + 1 - i], -i, -1);

	ans -= dp[L];
	if(ans < 0)
		cout << "impossible\n";
	else cout << ans << '\n';
}
