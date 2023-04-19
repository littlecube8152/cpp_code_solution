/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

int dp[1000001][241], t, n, m = 0;
deque<int> dq[1000005];
vector<int> v[1000005];
signed main()
{
    //fast;
    for (int i = 3; i <= n; i++)
    {
        for (int j = ceil(sqrt(n)); j > 0; j--)
        {
            if (j * j != n && i % (i / j) == 0)
                dq[i].push_back(i / j);
            if (j >= 3 && i % j == 0)
                dq[i].push_front(i / j);
        }
        while (!dq[i].empty())
        {
            v[i].emplace_back(dq[i].front());
            dq[i].pop_front();
        }
    }
    for (int i = 3; i <= 1000000; i++)
        for (int j : v[i])
        {
            for (int k = 3; k < j; k++)
                if (j % k == 0)
                    if (dp[i - j][k] != 0)
                        dp[i][j] = max(dp[i][j], dp[i - j][k] + 1);
        }
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cin >> n;
        int ans = 0;
        for (int i = 3; i <= 1000000; i++)
            ans = max(ans, dp[n][i]);
        cout << "Case #" << test << ": " << ans << '\n';
    }
}
