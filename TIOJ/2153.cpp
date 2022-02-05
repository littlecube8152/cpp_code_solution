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
using namespace __gnu_pbds;

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

int N, M, K, dp[2][(1 << 17)][2];

signed main()
{
    fast;
    cin >> N >> M >> K;

    dp[0][(1 << M) - 1][0] = 1;

    for (int i = 0, idx = 0; i < N; i++)
        for (int j = 0; j < M; j++, idx ^= 1)
        {
            for (int mask = 0; mask < (1 << M); mask++)
                dp[idx ^ 1][mask][0] = dp[idx ^ 1][mask][1] = 0;
            for (int mask = 0; mask < (1 << M); mask++)
                for (int k = 0; k <= 1; k++)
                {

                    bitset<20> bit = mask;

                    if (dp[idx][mask][k] != 0)
                    {
                        //cout << "DP " << i << " " << j << " " << bit << " " << k << " | " << dp[idx][mask][k] << '\n';
                        if (j == 0)
                        {
                            // XX----
                            // O <- this place must be open
                            if ((bit[0] == 1) + (bit[1] == 1) == 0)
                                dp[idx ^ 1][mask | 1][bit[0]] = (dp[idx ^ 1][mask ^ 1][bit[0]] + dp[idx][mask][k]) % K;
                            // XO----
                            // ? <- whatever
                            //
                            else if ((bit[0] == 1) + (bit[1] == 1) >= 1)
                            {
                                dp[idx ^ 1][mask | 1][bit[0]] = (dp[idx ^ 1][mask ^ 1][bit[0]] + dp[idx][mask][k]) % K;
                                dp[idx ^ 1][(mask | 1) ^ 1][bit[0]] = (dp[idx ^ 1][(mask | 1) ^ 1][bit[0]] + dp[idx][mask][k]) % K;
                            }
                        }
                        else if (j == M - 1)
                        {
                            // ----XX  ----XO  ----OX
                            //     OO      XO      XO
                            if ((bit[j - 1] == 1) + (bit[j] == 1) + k == 1)
                                dp[idx ^ 1][mask | (1 << j)][0] = (dp[idx ^ 1][mask | (1 << j)][0] + dp[idx][mask][k]) % K;

                            // ----XO  ----OX  ----OO  ----OO
                            //     O?      O?      X?      O?
                            else if ((bit[j - 1] == 1) + (bit[j] == 1) + k >= 2)
                            {
                                dp[idx ^ 1][mask | (1 << j)][0] = (dp[idx ^ 1][mask | (1 << j)][0] + dp[idx][mask][k]) % K;
                                dp[idx ^ 1][(mask | (1 << j)) ^ (1 << j)][0] = (dp[idx ^ 1][(mask | (1 << j)) ^ (1 << j)][0] + dp[idx][mask][k]) % K;
                            }
                        }
                        else
                        {
                            // --XX--  --XO--  --OX--
                            //   OO      XO      XO
                            if ((bit[j - 1] == 1) + (bit[j] == 1) + k == 1)
                                dp[idx ^ 1][mask | (1 << j)][bit[j]] = (dp[idx ^ 1][mask | (1 << j)][bit[j]] + dp[idx][mask][k]) % K;

                            // --XO--  --OX--  --OO--  --OO--
                            //   O?      O?      X?      O?
                            else if ((bit[j - 1] == 1) + (bit[j] == 1) + k >= 2)
                            {
                                dp[idx ^ 1][mask | (1 << j)][bit[j]] = (dp[idx ^ 1][mask | (1 << j)][bit[j]] + dp[idx][mask][k]) % K;
                                dp[idx ^ 1][(mask | (1 << j)) ^ (1 << j)][bit[j]] = (dp[idx ^ 1][(mask | (1 << j)) ^ (1 << j)][bit[j]] + dp[idx][mask][k]) % K;
                            }
                        }
                    }
                }
        }
    int ans = 0;
    for (int mask = 0; mask < (1 << M); mask++)
        for (int k = 0; k <= 1; k++)
            ans = (ans + dp[(N * M) & 1][mask][k]) % K;

    cout << ans << '\n';
}
