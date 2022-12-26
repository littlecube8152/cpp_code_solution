#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
ll h[5005], pos[5005], dp[5005], val[5005][5005], cost[5005][5005];

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
        pos[h[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            val[i][j] = val[i][j - 1] + (pos[j] > pos[i]);
    for (int i = 1; i <= N; i++)
    {
        cost[i][i] = val[i][i - 1];
        for (int j = i + 1; j <= N; j++)
            cost[i][j] = cost[i][j - 1] + val[j][i - 1] + j - i - (val[j][j - 1] - val[j][i - 1]);
    }
    // for (int i = 1; i <= N; i++)
    ////    for (int j = 1; j <= N; j++)
    //        cout << cost[i][j] << " \n"[j == N];
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 2e9;
        for (int j = 0; j <= i - 1; j++)
            dp[i] = min(dp[i], dp[j] + cost[j + 1][i]);
    }
    cout << dp[N] << '\n';
}