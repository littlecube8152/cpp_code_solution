#include <bits/stdc++.h>
using namespace std;

int N, a[5005], dp[5005][5005];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    vector<int> ord;
    for (int i = 0; i <= N; i++)
        ord.emplace_back(i);
    reverse(ord.begin(), ord.end());
    stable_sort(ord.begin(), ord.end(), [&](int i, int j)
                { return a[i] < a[j]; });

    for (int i = 1; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        int mx = 0;
        for (auto j : ord)
            if (j < i)
                mx = max(mx, dp[i][j]);
            else if (j > i)
                dp[j][i] = max(dp[j][i], mx + 1);
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j < i; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}