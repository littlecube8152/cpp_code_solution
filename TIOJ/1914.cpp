#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int t, n, c, arr[205], dp[205][205];
bool cdp[205][205];

int DP(int i, int j)
{

    if (i == j)
        return 1;

    if (cdp[i][j] == 0)
    {
        dp[i][j] = 1 << 30;
        for (int k = i; k < j; k++)
            dp[i][j] = min(dp[i][j], DP(i, k) + DP(k + 1, j) - (arr[i] == arr[j]));
        //printf("DP %d %d l=%d r=%d\n", i, j, l, r);
        cdp[i][j] = 1;
    }
    return dp[i][j];
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cdp[i][j] = 0, dp[i][j] = 0;
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        cout << DP(1, n) << '\n';
    }
}