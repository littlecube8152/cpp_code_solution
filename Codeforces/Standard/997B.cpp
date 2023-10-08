/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll C = 20000;
int dp[C + 50];

signed main()
{
    fast;
    for (int i = 1; i <= C; i++)
        dp[i] = 2e9;
    for (int i = 0; i < C; i++)
    {
        dp[i + 4] = min(dp[i + 4], dp[i] + 1);
        dp[i + 9] = min(dp[i + 9], dp[i] + 1);
        dp[i + 49] = min(dp[i + 49], dp[i] + 1);
    }
    ll n, ans = 0;
    cin >> n;
    for (int i = 0; i <= 49 * min(40LL, n); i++)
        if (dp[i] <= min(40LL, n))
            ans++;
    cout << ans + max(0LL, n - 40) * 49 << '\n';
}
