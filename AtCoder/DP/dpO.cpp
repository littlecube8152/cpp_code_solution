#pragma GCC optimize("Ofast,unroll-loops")
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

int n, arr[25][25], dp[22][1 << 22];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << n); j++)
        {
            bitset<22> b = j;
            if (b.count() == i)
                for (int k = 0; k < n; k++)
                    if (arr[i][k])
                        if (j & (1 << k))
                        {
                            dp[i][j] += dp[i - 1][j - (1 << k)];
                            if (dp[i][j] > MOD)
                                dp[i][j] -= MOD;
                        }
        }

    cout << dp[n][(1 << n) - 1];
}