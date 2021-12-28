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

char mp[1005][1005];
int h, w, dp[1005][1005];

signed main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> mp[i][j];
    dp[0][1] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (mp[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    cout << dp[h][w];
}