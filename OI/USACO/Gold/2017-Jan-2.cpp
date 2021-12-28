//#pragma GCC optimize("O3,unroll-loops")
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

ll n, k, arr[100005], dp[100005][21][4], res;
signed main()
{
    ifstream cin;
    cin.open("hps.in");
    ofstream cout;
    cout.open("hps.out");

    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'H')
            arr[i] = 0;
        else if (c == 'P')
            arr[i] = 1;
        else if (c == 'S')
            arr[i] = 2;
    }
    dp[1][0][0] = (arr[1] == 0);
    dp[1][0][1] = (arr[1] == 1);
    dp[1][0][2] = (arr[1] == 2);
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[(i - 1)][0][0] + (arr[i] == 0);
        dp[i][0][1] = dp[(i - 1)][0][1] + (arr[i] == 1);
        dp[i][0][2] = dp[(i - 1)][0][2] + (arr[i] == 2);

        for (int j = 1; j <= k; j++)
        {
            dp[i][j][0] = max({dp[(i - 1)][j][0], dp[(i - 1)][j - 1][1], dp[(i - 1)][j - 1][2]}) + (arr[i] == 0);
            dp[i][j][1] = max({dp[(i - 1)][j][1], dp[(i - 1)][j - 1][0], dp[(i - 1)][j - 1][2]}) + (arr[i] == 1);
            dp[i][j][2] = max({dp[(i - 1)][j][2], dp[(i - 1)][j - 1][1], dp[(i - 1)][j - 1][0]}) + (arr[i] == 2);
        }
    }
    for (int i = 0; i <= k; i++)
        res = max({res, dp[n][i][0], dp[n][i][1], dp[n][i][2]});
    cout << res << '\n';
}