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

ll n, h[100005], dp[100005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        dp[i] = 1000000000000;
    }

    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }
    cout << dp[n] << '\n';
}