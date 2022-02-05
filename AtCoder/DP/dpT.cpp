/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, dp[3005][3005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[1][i] = i;
    for (int i = 2; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '<')
            for (int j = 1; j <= n - i + 1; j++)
                dp[i][j] = (dp[i - 1][j] - dp[i - 1][0] + MOD) % MOD;
        else
            for (int j = 1; j <= n - i + 1; j++)
                dp[i][j] = (dp[i - 1][n - i + 2] - dp[i - 1][j] + MOD) % MOD;
        for (int j = 1; j <= n;j++)
            dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD;
    }
    cout << dp[n][1] << '\n';
    
}
