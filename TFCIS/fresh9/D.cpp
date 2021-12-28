#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

int N, dp[2005][2005], arr[2005][2005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + arr[i][j]});
    cout << dp[N][N] << '\n';
}