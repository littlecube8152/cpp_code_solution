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

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k, table[45][45] = {}, dp[2005][2005] = {};
        pii p[2005] = {};
        cin >> n >> k;
        pii pos = {1, 1}, d = {0, 1};
        for (int i = 0; i <= n + 1; i++)
            table[i][0] = table[i][n + 1] = table[0][i] = table[n + 1][i] = -1;
        for (int i = 1; i <= n * n; i++)
        {
            table[pos.F][pos.S] = i;
            p[i] = pos;
            pos.F += d.F, pos.S += d.S;
            if (table[pos.F][pos.S] != 0)
            {
                pos.F -= d.F, pos.S -= d.S;
                swap(d.F, d.S);
                d.S = -d.S;
                pos.F += d.F, pos.S += d.S;
            }
        }
        dp[n * n][0] = 1;
        for (int i = n * n - 1; i >= 1; i--)
        {
            for (int dx = -1; dx <= 1; dx++)
                for (int dy = -1; dy <= 1; dy++)
                    if (abs(dx) + abs(dy) == 1 && table[p[i].F + dx][p[i].S + dy] > i)
                    {
                        int j = table[p[i].F + dx][p[i].S + dy];
                        for (int k = 1; k <= n * n; k++)
                            if (dp[j][k - 1])
                                dp[i][k] = j;
                    }
        }
        if (!dp[1][k])
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        else
        {
            vector<int> v;
            vector<pii> sol;
            v.emplace_back(1);
            while (v.back() != n * n)
                v.emplace_back(dp[v.back()][k--]);
            for (int i = 1; i < v.size(); i++)
                if (v[i - 1] + 1 != v[i])
                    sol.emplace_back(pii(v[i - 1], v[i]));
            cout << "Case #" << t << ": " << sol.size() << '\n';
            //for (auto [i, j] : sol)
            //    cout << i << " " << j << '\n';
        }
    }
}