/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
// using namespace __gnu_pbds;

const ll mod = MOD2;
ll n, d, dp[505][1 << 11];

void debug(int i, int mask)
{
    bitset<5> b = mask;
    cout << i << ' ' << b << ' ' << dp[i][mask] << '\n';
}


signed main()
{
    fast;
    cin >> n >> d;
    dp[0][(1 << d) - 1] = 1;
    int range = (1 << (2 * d + 1)) - 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
            for (int mask = 0; mask < (1 << (2 * d + 1)); mask++)
            {
                int nxt = ((mask << 1) ^ 1) & range;
                for (int j = 0; j <= 2 * d; j++)
                    if ((1 << j) & nxt)
                        dp[i][nxt ^ (1 << j)] = (dp[i][nxt ^ (1 << j)] + dp[i - 1][mask]) % mod;
            }
        else
        {
            int cur = 1 << (i - a + d);
            for (int mask = 0; mask < (1 << (2 * d + 1)); mask++)
            {
                int nxt = ((mask << 1) ^ 1) & range;
                if (cur & nxt)
                    dp[i][nxt ^ cur] = (dp[i][nxt ^ cur] + dp[i - 1][mask]) % mod;
            }
        }
    }
    cout << dp[n][(1 << d) - 1] << '\n';
}
