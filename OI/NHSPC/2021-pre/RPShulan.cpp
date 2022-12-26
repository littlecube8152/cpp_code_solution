#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

// R = 0, P = 1, S = 2
//   R P S
// R - ^ <
// P < - ^
// S ^ < -

int t, n, m, cost[10005][3];
char s[10005];
bool dp[10005][20005];
pii rev[10005][10005];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
}

void solve()
{
    for (int i = 0; i <= m; i++)
        cost[i][0] = cost[i][1] = cost[i][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R')
            cost[i % m][1]++, cost[i % m][2]--;
        else if (s[i] == 'P')
            cost[i % m][2]++, cost[i % m][0]--;
        else
            cost[i % m][0]++, cost[i % m][1]--;
    }
    for (int i = 0; i <= m; i++)
        for (int j = n / 2; j <= 2 * n; j++) /***************/
            dp[i][j] = 0;
    dp[0][n] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = n / 2; j <= 2 * n; j++) /***************/
            if (0 <= j - cost[i % m][0] && j - cost[i % m][0] <= 2 * n && dp[i - 1][j - cost[i % m][0]])
                dp[i][j] = 1, rev[i][j] = {j - cost[i % m][0], 0};
            else if (0 <= j - cost[i % m][1] && j - cost[i % m][1] <= 2 * n && dp[i - 1][j - cost[i % m][1]])
                dp[i][j] = 1, rev[i][j] = {j - cost[i % m][1], 1};
            else if (0 <= j - cost[i % m][2] && j - cost[i % m][2] <= 2 * n && dp[i - 1][j - cost[i % m][2]])
                dp[i][j] = 1, rev[i][j] = {j - cost[i % m][2], 2};
    for (int i = n + 1; i <= 2 * n; i++) /***************/
        if (dp[m][i])
        {
            string c = string(m, ' ');
            int score = i;
            for (int j = m; j >= 1; j--)
            {
                c[j - 1] = (rev[j][score].S == 0 ? 'R' : (rev[j][score].S == 1 ? 'P' : 'S'));
                score = rev[j][score].F;
            }
            cout << i - n << '\n'
                 << c << '\n';
            return;
        }
    cout << "-1\nimpossible\n";
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--)
    {
        init();
        solve();
    }
}