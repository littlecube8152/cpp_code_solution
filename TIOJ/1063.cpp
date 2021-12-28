#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, r = 0, b[201][201];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = b[i][j] + b[i - 1][j];

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int dp[201] = {0}, a = 0;
            for (int k = 1; k <= m; k++)
            {
                if (b[j][k] - b[i - 1][k] == (j - i + 1))
                {
                    dp[k] = dp[k - 1] + j - i + 1;
                    a = max(a, dp[k]);
                }
            }
            r = max(r, a);
        }
    cout << r << '\n';
}