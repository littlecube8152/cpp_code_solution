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

ll n, dp[70000], g[20][20], sum[70000];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 1; i < (1LL << n); i++)
    {
        bitset<16> b = i;
        for (int k = 0; k < n; k++)
            if (b[k])
                for (int l = 0; l < n; l++)
                    if (b[l])
                        sum[i] += g[k][l];
        sum[i] /= 2;
    }
    for (int i = 1; i < (1LL << n); i++)
    {
        for (int j = i;; j = ((j - 1) & i))
        {
            dp[i] = max(dp[i], dp[j] + sum[i - j]);
            if (j == 0)
                break;
        }
    }
    cout << dp[((1LL << n) - 1LL)] << '\n';
}
