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

const int INF = 1e6;
int T, N, M, A[9005], dp[10004], fr[9005][5005], occ[5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        for (int i = 1; i <= N; i++)
            A[i] = (A[i] + A[i - 1]) % M;

        fill(occ, occ + M, INF);
        for (int j = 0; j < M; j++)
            fr[N + 1][j] = INF;
        for (int i = N; i >= 0; i--)
        {
            for (int j = 0; j < M; j++)
                // Ak - Ai = j, Ak = Ai + j
                fr[i][j] = min(occ[(A[i] + j) % M], fr[i + 1][j]);
            occ[A[i]] = i;
        }

        fill(dp, dp + 2 * M, INF);
        dp[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(pii(0, 0));

        int ans = 0;
        while (!pq.empty())
        {
            auto [i, h] = pq.top();
            pq.pop();
            if (dp[h] < i)
                continue;
            ans++;
            for (int k = 0; k < M; k++)
                if (dp[h ^ k] > fr[i][k])
                    dp[h ^ k] = fr[i][k], pq.push(pii(dp[h ^ k], h ^ k));
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}