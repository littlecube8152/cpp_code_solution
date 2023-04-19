/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, c, dp[5005][5005];

ll solve(vector<pll> v)
{
    vector<ll> a, b;
    ll N, M;
    for (auto [pos, type] : v)
        if (type == 0)
            a.emplace_back(pos);
        else
            b.emplace_back(pos);
    N = a.size();
    M = b.size();
    a.emplace_back(0);
    b.emplace_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = 1e18;
    dp[N][M] = 0;
    for (int i = N; i >= 0; i--)
        for (int j = M; j >= 0; j--)
        {
            if (i >= 2)
                dp[i - 2][j] = min(dp[i - 2][j], dp[i][j] + c + 2 * a[i]);
            if (i >= 1)
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + 2 * a[i]);
            if (j >= 2)
                dp[i][j - 2] = min(dp[i][j - 2], dp[i][j] + c + 2 * b[j]);
            if (j >= 1)
                dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + 2 * b[j]);
            if (i >= 1 && j >= 1)
                dp[i - 1][j - 1] = min(dp[i - 1][j - 1], dp[i][j] + 2 * max(a[i], b[j]));
        }
    return dp[0][0];
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> c;
        vector<pll> pos, neg;
        for (int i = 1; i <= n; i++)
        {
            pll p;
            cin >> p.F >> p.S;
            if (p.F > 0)
                pos.emplace_back(p);
            else
                neg.emplace_back(pll(-p.F, p.S));
        }
        cout << "Case #" << t << ": " << solve(pos) + solve(neg) << "\n";
    }
}