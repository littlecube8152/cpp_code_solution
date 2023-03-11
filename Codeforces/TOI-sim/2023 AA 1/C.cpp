#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int N, nz[5005], a[10005];
bool can[5005][10005];
ll dp[5005][5005], p[5005], ans;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = N + 1; i <= 2 * N; i++)
        a[i] = a[i - N];
    for (int i = 1; i <= N; i++)
        dp[i][i - 1] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            if (a[j])
                nz[i] = j;
    for (int i = 1; i <= N; i++)
    {
        int f = 0;
        for (int j = i; j <= 2 * N; j++)
        {
            if (a[j])
            {
                if (f == 0 || f == a[j])
                    f = a[j];
                else
                    break;
            }
            if (f == 0 || j - i + 1 == f)
                can[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
            p[j] = dp[i][j];
        for (int j = i; j <= N; j++)
        {
            dp[i][j] = (p[j - 1] - (nz[j] > 0 ? p[nz[j] - 1] : 0) + mod) % mod; // sum [i, j - 1] ~ [i, nz[j]]
            if (nz[j] != 0 &&
                nz[j] >= j - a[nz[j]] + 1 && j - a[nz[j]] + 1 > 0 &&
                can[j - a[nz[j]] + 1][j])
                dp[i][j] = (dp[i][j] + dp[i][j - a[nz[j]]]) % mod;
            p[j] = (p[j - 1] + dp[i][j]) % mod;
        }
    }
    // for (int i = 1; i <= N; i++)
    //     for (int j = 1; j <= N; j++)
    //         cout << dp[i][j] << " \n"[j == N];
    ans = dp[1][N];
    for (int i = 2; i <= N; i++)
        for (int j = N + 1; j < N + i; j++)
            if (can[i][j])
            {
                // cout << i << " -> " << j << ' ' << dp[j - N + 1][i - 1] << '\n';
                ans = (ans + dp[j - N + 1][i - 1]) % mod;
            }
    for (int i = 1; i <= N; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= N; j++)
            if (a[j] != 0 && a[j] != i)
                flag = 0;
        if (flag && N % i == 0)
            ans = (ans - (i - 1) + mod) % mod;
    }
    cout << ans << '\n';
}

// 1 1 1 1 v
// 2 2 1 1 v
// 1 2 2 1 v
// 1 1 2 2 v
// 2 1 1 2 v
// 2 2 2 2 v
// 1 3 3 3 v
// 3 3 3 1 v
// 3 1 3 3
// 3 3 1 3
// 4 4 4 4 v
