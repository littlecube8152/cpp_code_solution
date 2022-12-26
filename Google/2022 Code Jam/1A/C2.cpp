/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, w, x[105][105], dp[105][105], m[105][105][105], ans;

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ans = 0;
        cin >> n >> w;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= w; j++)
            {
                cin >> x[i][j];
                ans += x[i][j] * 2;
            }
        for (int i = 1; i <= n; i++)
        {
            for (int k = 1; k <= w; k++)
                m[i][i - 1][k] = 100;

            for (int j = i; j <= n; j++)
            {
                dp[i][j] = 0;
                for (int k = 1; k <= w; k++)
                    m[i][j][k] = min(m[i][j - 1][k], x[j][k]);
            }
        }
        for (int l = 0; l < n; l++)
            for (int i = 1; i <= n - l; i++)
            {
                int j = i + l, cost = 0;
                for (int k = 1; k <= w; k++)
                    cost += m[i][j][k];
                for (int k = i; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
            }
            
        cout << "Case #" << t << ": " << ans - dp[1][n] * 2 << '\n';
    }
}