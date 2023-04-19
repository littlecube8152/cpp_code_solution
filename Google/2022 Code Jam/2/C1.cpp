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

const pll nsoln = pll(-1, -1);
pll p[10], s[11], dp[1 << 20];
int n;

ll dis(pll p1, pll p2)
{
    return (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i].F >> p[i].S;
        for (int i = 0; i <= n; i++)
            cin >> s[i].F >> s[i].S;
        for (int mask = 0; mask < (1 << (2 * n)); mask++)
            dp[mask] = nsoln;
        dp[0] = pll(0, 0);
        for (int mask = 0; mask < (1 << (2 * n)); mask++)
            if (dp[mask] != nsoln)
            {
                // bitset<6> b = mask;
                // cout << b << " " << dp[mask].F << " " << dp[mask].S << '\n';
                vector<int> ch, sw;
                for (int i = 0; i < n; i++)
                    if (((mask >> i) & 1) == 0)
                        ch.emplace_back(i);
                for (int i = 0; i < n; i++)
                    if (((mask >> (n + i)) & 1) == 0)
                        sw.emplace_back(i + 1);
                for (int i : ch)
                {
                    sort(sw.begin(), sw.end(), [&](int j1, int j2)
                         { return dis(p[i], s[j1]) < dis(p[i], s[j2]); });
                    ll pre = dis(p[i], s[0]);
                    for (int j : sw)
                        if (dis(p[i], s[j]) <= pre)
                        {
                            pre = dis(p[i], s[j]);
                            dp[mask ^ (1 << i) ^ (1 << (j + n - 1))] = pii(i, j);
                        }
                        else
                            break;
                }
            }
        if (dp[(1 << (2 * n)) - 1] == nsoln)
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        else
        {
            cout << "Case #" << t << ": POSSIBLE\n";
            vector<pii> v;
            int mask = (1 << (2 * n)) - 1;
            while (mask)
            {
                v.emplace_back(dp[mask]);
                auto [i, j] = dp[mask];
                mask = mask ^ (1 << i) ^ (1 << (j + n - 1));
            }
            reverse(v.begin(), v.end());
            for (auto [i, j] : v)
                cout << i + 1 << " " << j + 1 << '\n';
        }
    }
}