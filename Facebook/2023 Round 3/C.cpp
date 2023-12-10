#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const int INF = 1e18;
int T, N, M;
ll A[305][305], go[305][305], back[305][305], dp[305][305];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> A[i][j];
        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= M + 1; j++)
                go[i][j] = back[i][j] = 0, dp[i][j] = INF;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                go[i][j] = max(go[i - 1][j], go[i][j - 1]) + A[i][j];

        for (int i = N; i >= 1; i--)
            for (int j = M; j >= 1; j--)
                back[i][j] = max(back[i + 1][j], back[i][j + 1]) + A[i][j];

        dp[N][0] = 0;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                for (int k = j; k <= N; k++)
                {
                    ll cost = dp[k][i - 1];
                    ll from = max(go[j - 1][i], go[k - 1][i - 1]);
                    if (i >= 2)
                        from = max(from, go[k][i - 2]);
                            cost = max(cost, go[j - 1][i] + back[k + 1][i]);
                    cost = max(cost, go[k - 1][i - 1] + back[k + 1][i]);
                    if (i >=)
                }

        cout << "Case #" << t << ": " << dp[N][1] << '\n';
    }
}