#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[200005], dp[4][200005], k[4], n, m;

signed main()
{
    cin >> k[1] >> k[2] >> k[3];
    n = k[1] + k[2] + k[3];
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> m;
            a[m] = i;
        }
    
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = dp[1][i - 1] + (a[i] == 1 ? 0 : 1);
        dp[2][i] = min(dp[2][i - 1], dp[1][i - 1]) + (a[i] == 2 ? 0 : 1);
        dp[3][i] = min({dp[3][i - 1], dp[2][i - 1], dp[1][i - 1]}) + (a[i] == 3 ? 0 : 1);
    }
    cout << min({dp[1][n], dp[2][n], dp[3][n]});
}