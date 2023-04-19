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
#define int long long
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

int N;
char g[1010][1010];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> g[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int cnt = 0;
            if (i <= N - 5)
                for (int k = 0; k < 6; k++)
                    cnt += (g[i + k][j] == '#');
            if (cnt >= 4)
            {
                cout << "Yes\n";
                return 0;
            }
            cnt = 0;
            if (j <= N - 5)
                for (int k = 0; k < 6; k++)
                    cnt += (g[i][j + k] == '#');
            if (cnt >= 4)
            {
                cout << "Yes\n";
                return 0;
            }
            cnt = 0;
            if (i <= N - 5 && j <= N - 5)
                for (int k = 0; k < 6; k++)
                    cnt += (g[i + k][j + k] == '#');
            if (cnt >= 4)
            {
                cout << "Yes\n";
                return 0;
            }
            cnt = 0;
            if (i <= N - 5 && j > 5)
                for (int k = 0; k < 6; k++)
                    cnt += (g[i + k][j - k] == '#');
            if (cnt >= 4)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    cout << "No\n";
}


/*
6
.#...#
..#.#.
...#..
..#.#.
.....#
......
*/