#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dp[5005][5005];
string n, m;
signed main()
{
    cin >> n >> m;
    n = ' ' + n + ' ';
    m = ' ' + m + ' ';
    for (int i = 0; i <= n.size(); i++)
        for (int j = 0; j <= m.size(); j++)
            dp[i][j] = 10000000;
    dp[0][0] = 0;
    for (int i = 1; i <= n.size(); i++)
        for (int j = 1; j <= m.size(); j++)
        {
            if (n[i - 1] == m[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = min({dp[i][j], dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1});
        }
    cout << dp[n.size()][m.size()] << '\n';
}