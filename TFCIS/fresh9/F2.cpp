#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define pii pair<int, int>
int N, arr[25][25], dp[25][1 << 20], arrr[500005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    if (N > 20)
    {
        for (int i = 1; i <= N; i++)
        {
            int a, b;
            cin >> a >> b;
            arrr[a] = max(arrr[a], b);
        }
        long long res = 0;
        for (int i = 1; i <= N; i++)
        {
            res += arrr[i];
        }
        cout << res << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i][a] = b;
    }
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i][a] = -b;
    }
    for (int mask = 0; mask < (1 << N); mask++)
        for (int i = 0; i <= N; i++)
            dp[i][mask] = -1000000000000000;
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << N); mask++)
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < N; j++)
                if (mask & (1 << j))
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + arr[i][j + 1]);
    cout << dp[N][(1 << N) - 1] << '\n';
}