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
 
ll n, v[4][100005], dp[4][100005];
 
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[1][i] >> v[2][i] >> v[3][i];
 
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = max(dp[2][i - 1], dp[3][i - 1]) + v[1][i];
        dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]) + v[2][i];
        dp[3][i] = max(dp[2][i - 1], dp[1][i - 1]) + v[3][i];
    }
 
    cout << max({dp[1][n], dp[2][n], dp[3][n]}) << '\n';
}