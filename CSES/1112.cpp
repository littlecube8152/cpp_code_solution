/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, m, f[105], dp[1005][105];
const ll mod = 1000000007;
string s;

signed main()
{
    fast;
    cin >> n >> s;
    m = s.size();
    s = ' ' + s;
    f[0] = -1;
    for (int i = 1, j = -1; i <= m; i++)
    {
        while (j >= 0)
            if (s[i] == s[j + 1])
                break;
            else
                j = f[j];
        f[i] = ++j;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            for (char c = 'A'; c <= 'Z'; c++)
            {
                int cur = j;
                while (cur >= 0)
                    if (s[cur + 1] != c)
                        cur = f[cur];
                    else
                        break;
                dp[i + 1][cur + 1] = (dp[i + 1][cur + 1] + dp[i][j]) % mod;
            }
        dp[i + 1][m] = (dp[i + 1][m] + dp[i][m] * 26) % mod;
    }
    cout << dp[n][m] << '\n';
}
