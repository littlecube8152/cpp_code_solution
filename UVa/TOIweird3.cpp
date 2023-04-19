#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[1000005], bit[1000005], res[1000005] = 0, ans = 0;

signed main()
{
    fast;
    int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = a[i]; j > 0; j -= (j & -j))
			res[i] += bit[j];
		ans += res[i];
		for(int j = a[i]; j <= n; j += (j & -j))
			bit[j]++;
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans << '\n';
		
	}
	
}
