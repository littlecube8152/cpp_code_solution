/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = MOD;
const ll inv26 = 729486258;

ll p, n, m, k, dp[2][2];

signed main()
{
    fast;
    char c;
    cin >> p >> n;
    for (int i = 1; i <= n; i++)
        cin >> c;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> c;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> c;
    dp[0][1] = 1;
    for (int i = 1; i <= p; i++)
    {
        dp[i & 1][1] = ((dp[(i & 1) ^ 1][1] * (26 - m - k) % mod) * inv26 % mod +
                        (dp[(i & 1) ^ 1][0] * (n + k) % mod) * inv26 % mod) %
                       mod;
        dp[i & 1][0] = ((dp[(i & 1) ^ 1][0] * (26 - n - k) % mod) * inv26 % mod +
                        (dp[(i & 1) ^ 1][1] * (m + k) % mod) * inv26 % mod) %
                       mod;
    }
    cout << (dp[p & 1][1] - dp[p & 1][0] + mod) % mod << '\n';
}
