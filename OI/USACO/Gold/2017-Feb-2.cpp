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

int n, dp[505][505];
char arr[505][505];

signed main()
{
    //fast;
    ifstream cin;
    cin.open("palpath.in");
    ofstream cout;
    cout.open("palpath.out");
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        dp[i][n - i + 1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i, k = n; j <= n && k >= 2; j++, k--)
        {
            /*
            if (2 * n + 2 - 2 * k - j > 0)
            {
                if (arr[j][k] == arr[2 * n + 2 - 2 * k - j][k])
                {
                    printf("P %d %d -> %d %d\n", j, k, 2 * n + 2 - 2 * k - j, k);
                    dp[2 * n + 2 - 2 * k - j][k] = (dp[2 * n + 2 - 2 * k - j][k] + dp[2 * n + 3 - 2 * k - j][k]) % MOD;
                }
            }
            if (2 * n + 2 - 2 * j - k > 0)
            {
                if (arr[j][k] == arr[j][2 * n + 2 - 2 * j - k])
                {
                    printf("P %d %d -> %d %d\n", j, k, j, 2 * n + 2 - 2 * j - k);
                    dp[j][2 * n + 2 - 2 * j - k] = (dp[j][2 * n + 2 - 2 * j - k] + dp[j][2 * n + 3 - 2 * j - k]) % MOD;
                }
            }*/
            for (int l = 2 * n + 3 - 2 * k - j, m = k - 1; l < j && m > 0; l++, m--)
            {

                if (1 <= l && l <= n && 1 <= m && m <= n)
                    if (arr[l][m] == arr[j][k])
                    {
                        //printf("P %d %d -> %d %d\n", j, k, m, l);
                        dp[l][m] = (dp[l][m] + dp[l + 1][m] + dp[l][m + 1]) % MOD;
                    }
            }
        }
        /*
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                cout << dp[j][k] << " \n"[k == n];
        cout << '\n';*/
    }
    cout << dp[1][1] << '\n';
}