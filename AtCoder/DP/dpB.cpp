#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n,k, h[100005], dp[100005];

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        dp[i] = 1000000000000;
    }

    dp[1] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k && i + j <= n;j++)
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    
    cout << dp[n] << '\n';
}