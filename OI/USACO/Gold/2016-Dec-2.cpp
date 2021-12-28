#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct point
{
    int x, y;
    int operator-(point p)
    {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

int n, m, dp[1005][1005][2];
point h[1005], g[1005];
signed main()
{
    fast;
    ifstream cin("checklist.in");
    ofstream cout("checklist.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i].x >> h[i].y;

    for (int i = 1; i <= m; i++)
        cin >> g[i].x >> g[i].y;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= 1; k++)
                dp[i][j][k] = 200000000000000;
    dp[1][0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i)
                dp[i][j][0] = min({dp[i][j][0],
                                   dp[i - 1][j][0] + (h[i - 1] - h[i]),
                                   dp[i - 1][j][1] + (g[j] - h[i])});
            if (j)
                dp[i][j][1] = min({dp[i][j][1],
                                   dp[i][j - 1][0] + (h[i] - g[j]),
                                   dp[i][j - 1][1] + (g[j - 1] - g[j])});
        }
    cout << dp[n][m][0] << '\n';
}