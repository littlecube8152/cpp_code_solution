/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

ll k;
double dp[105][10][10], res[10][10], ans;

signed main()
{
    fast;

    cin >> k;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            res[i][j] = 1;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            for (int p = 0; p <= k; p++)
                for (int x = 1; x <= 8; x++)
                    for (int y = 1; y <= 8; y++)
                        dp[p][x][y] = 0;

            dp[0][i][j] = 1.0;
            for (int p = 0; p < k; p++)
                for (int x = 1; x <= 8; x++)
                    for (int y = 1; y <= 8; y++)
                    {
                        int div;
                        if ((x == 1 || x == 8) && (y == 1 || y == 8))
                            div = 2;
                        else if ((x == 1 || x == 8) || (y == 1 || y == 8))
                            div = 3;
                        else
                            div = 4;
                        dp[p + 1][x + 1][y] += dp[p][x][y] / double(div);
                        dp[p + 1][x - 1][y] += dp[p][x][y] / double(div);
                        dp[p + 1][x][y + 1] += dp[p][x][y] / double(div);
                        dp[p + 1][x][y - 1] += dp[p][x][y] / double(div);
                    }
            for (int x = 1; x <= 8; x++)
                for (int y = 1; y <= 8; y++)
                    res[x][y] *= (1.0 - dp[k][x][y]);
        }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            ans += res[i][j];
    cout << fixed << setprecision(6) << ans << '\n';
}