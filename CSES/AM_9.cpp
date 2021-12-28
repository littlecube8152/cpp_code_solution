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
#define int long long
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

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m, k, dp[100][100][(1 << 10)];

signed main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < (1 << m); i++)
        dp[m][__builtin_popcount(i)][i] = (__builtin_popcount(i) >= k);
    for (int i = m + 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int mask = 0; mask < (1 << m); mask++)
                if (__builtin_popcount(mask) >= k)
                    dp[i][j][mask] = dp[i - 1][j - (mask & 1)][(1 << (m - 1)) + mask / 2] + 
                                     dp[i - 1][j - (mask & 1)][mask / 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int cnt = 0;
            for (int mask = 0; mask < (1 << m); mask++)
                cnt += dp[i][j][mask];
            if (cnt > 0)
            {
                cout << i << " = " << cnt << " (" << j << ")\n";
                goto nxt;
            }
        }
        cout << i << " = " << 0 << "\n";
    nxt:
        continue;
    }
}
/*
m  k  ans
2  1  0 2 [1  3][1  4][1  5 ][1   6]
3  1  0 0 [3  2  1][6  3  1 ][10  4  1][15  5 1]
3  2  0 0  3 [1  3  6][1  4   10][1  5  15][1 6 21]
4  1  0 0  0 [4  3  2  1][10  6   3  1][20  10 4 1][35 15 5 1]
4  2  0 0  0  6  3 [1  6  20  6 ][1  10 50  10][1 15 105 15]
4  3  0 0  0  4 [1  3  6  10][1   4  10 20][1 5 15 35][1 6 21 56]
5  1  0 0  0  0 [5  4  3  2   1 ][15 10 6   3 1]
*/