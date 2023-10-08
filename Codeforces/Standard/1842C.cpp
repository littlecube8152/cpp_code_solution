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

ll t, n, a, dp[200005], val[200005];

signed main()
{
    fast;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            val[i] = -1e9;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            dp[i] = max(dp[i - 1], i + val[a]);
            val[a] = max(val[a], dp[i - 1] - i + 1);
        }
        cout << dp[n] << '\n';
    }
}
