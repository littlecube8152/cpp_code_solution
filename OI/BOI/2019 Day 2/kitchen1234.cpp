#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, A[305], B[305], sumA;
bool dp[1605][1605];

void fail(bool args)
{
    if (args)
    {
        cout << "Impossible\n";
        exit(0);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    fail(K > M);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        fail(A[i] < K);
        sumA += A[i];
    }
    for (int i = 0; i < M; i++)
        cin >> B[i];

    int ans = 1e9;
    if (M <= 15)
    {
        for (int mask = 0; mask < (1 << M); mask++)
        {
            int tot = 0, restot = 0;
            for (int i = 0; i < M; i++)
                if (mask & (1 << i))
                    tot += B[i], restot += min(N, B[i]);
            if (tot < sumA)
                continue;
            bool valid = (restot >= N * K);
            if (valid)
                ans = min(ans, tot - sumA);
        }
        fail(ans >= 1e8);
        cout << ans << '\n';
    }
    else if (K == 1)
    {
        bitset<90005> b;
        b[0] = 1;
        for (int i = 0; i < M; i++)
            b |= (b << B[i]);
        for (int i = sumA; i <= 300 * 300; i++)
            if (b[i])
            {
                cout << i - sumA << '\n';
                return 0;
            }
        cout << "Impossible\n";
    }
    else if (K <= 40)
    {
        dp[0][0] = 1;
        for (int i = 0; i < M; i++)
            for (int j = N * M; j >= 0; j--)
                for (int k = M * 40; k >= 0; k--)
                    if (j >= min(N, B[i]) && k >= B[i])
                        dp[j][k] |= dp[j - min(N, B[i])][k - B[i]];
        for (int i = sumA; i <= M * 40; i++)
            for (int j = N * K; j <= N * M; j++)
                if (dp[j][i])
                {
                    cout << i - sumA << '\n';
                    return 0;
                }
        cout << "Impossible\n";
    }
}