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

int T, N, dp[1 << 21], val[21][21];

signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> val[i][j];
        for (int i = 0; i < (1 << N); i++)
            if (__builtin_popcount(i) % 3 == 0)
                dp[i] = 1e8;
        dp[0] = 0;
        for (int i = 1; i < (1 << N); i++)
        {
            int a = __lg(i & -i);
            if (__builtin_popcount(i) % 3 == 0 && a >= (N - __builtin_popcount(i)) / 3)
            {
                for (int b = a + 1; b < N; b++)
                    if ((1 << b) & i)
                        for (int c = b + 1; c < N; c++)
                            if ((1 << c) & i)
                                dp[i] = min(dp[i ^ (1 << a) ^ (1 << b) ^ (1 << c)] + val[a][b] + val[b][c] + val[a][c], dp[i]);
            }
        }
        cout << dp[(1 << N) - 1] << '\n';
    }
}
