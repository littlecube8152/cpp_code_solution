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

ll n, m, vis[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 46, 17, 50, 3, 6, 31, 52},
                      {0, 18, 49, 2, 7, 30, 51, 56, 5},
                      {0, 45, 64, 47, 16, 27, 4, 53, 32},
                      {0, 48, 19, 8, 29, 10, 55, 26, 57},
                      {0, 63, 44, 11, 22, 15, 28, 33, 54},
                      {0, 12, 41, 20, 9, 36, 23, 58, 25},
                      {0, 43, 62, 39, 14, 21, 60, 37, 34},
                      {0, 40, 13, 42, 61, 38, 35, 24, 59}};


signed main()
{
    fast;
    cin >> m >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            cout << (vis[i][j] - vis[n][m] + 64) % 64 + 1 << " \n"[j == 8];
}
