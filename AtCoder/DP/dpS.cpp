/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll D, dp[10001][10][100], ans;
string K;
signed main()
{
    cin >> K >> D;
    dp[0][0][0] = 1;
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < D; k++)
                for (int l = 0; l < 10; l++)
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][l][(k + 10 * D - j) % D]) % MOD;
    for (int i = 0, r = 0; i < K.length(); i++)
    {
        for (int j = K[i] - '0' - 1; j >= 0; j--)
        {
            ans = (ans + dp[K.length() - i][j][r]) % MOD;
            //cout << j << " " << K.length() - i << " " << dp[K.length() - i][j][r] << '\n';
        }
        r = (r + 10 * D - (K[i] - '0')) % D;
    }

    int r = 0;
    for (int i = 0; i < K.length(); i++)
        r = (r + (K[i] - '0')) % D;
    if(r == 0)
        ans++;

    cout << (ans + MOD - 1) % MOD << '\n';
}
