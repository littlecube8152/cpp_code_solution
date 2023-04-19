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
//#pragma pack(0)
//#define int long long
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

int n, w, x[11][4], ans = 0;
map<string, int> dp[11];

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ans = 1e9;
        cin >> n >> w;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= w; j++)
            {
                cin >> x[i][j];
                ans += x[i][j];
            }
        for (int i = 0; i <= n; i++)
            dp[i].clear();
        dp[0][""] = 0;
        for (int i = 1; i <= n; i++)
        {
            string s;
            for (int j = 1; j <= w; j++)
                for (int k = 1; k <= x[i][j]; k++)
                    s += (char)('0' + j);
            do
            {
                dp[i][s] = 1e9;
                for (auto [t, val] : dp[i - 1])
                {
                    int lcs = 0;
                    for (; lcs < min(s.size(), t.size()); lcs++)
                        if (s[lcs] != t[lcs])
                            break;
                    dp[i][s] = min(dp[i][s], val + (int)s.size() + (int)t.size() - 2 * lcs);
                }
            } while (next_permutation(s.begin(), s.end()));
        }
        for(auto [s, val] : dp[n])
            ans = min(ans, val + (int)s.size());
        cout << "Case #" << t << ": " << ans << '\n';
    }
}