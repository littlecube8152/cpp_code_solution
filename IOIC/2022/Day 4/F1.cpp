#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, K, arr[100005], dp[100005][55];

int main()
{
    cin >> N >> K;
    assert(K <= 50);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
        {
            if (j >= 1)
                dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j] + arr[i], arr[i]});
            else
                dp[i][j] = max(dp[i - 1][j] + arr[i], arr[i]);
            ans = max(ans, dp[i][j]);
            
        }

    cout << ans << '\n';
}