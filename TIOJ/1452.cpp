/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
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
//using namespace __gnu_pbds;

long long N, M, dp[15][15][(1 << 14)];

signed main()
{
    //fast;
    while (cin >> N >> M)
    {
        if (N == 0 && M == 0)
            break;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                for (int mask = 0; mask < (1 << N); mask++)
                    dp[i][j][mask] = 0;
        dp[0][M][0] = 0;
        dp[0][0][0] = 1;
        for (int j = 0; j < M; j++)
            for (int i = 0; i < N; i++)
                for (int mask = 0; mask < (1 << N); mask++)
                    if (mask & (1 << i))
                    {
                        if (i != N - 1)
                            dp[i + 1][j][mask ^ (1 << i)] += dp[i][j][mask];
                        else
                            dp[0][j + 1][mask ^ (1 << i)] += dp[i][j][mask];
                    }
                    else
                    {
                        if (i != N - 1 && (mask & (1 << (i + 1))) == 0)
                            dp[i + 1][j][mask ^ (1 << (i + 1))] += dp[i][j][mask];
                        if (i != N - 1)
                            dp[i + 1][j][mask ^ (1 << i)] += dp[i][j][mask];
                        else
                            dp[0][j + 1][mask ^ (1 << i)] += dp[i][j][mask];
                    }


        cout << dp[0][M][0] << '\n';
    }
}
