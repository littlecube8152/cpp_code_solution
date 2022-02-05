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
    assert(K <= 40);
    fail(K > M);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sumA += A[i];
        fail(A[i] < K);
    }
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    dp[0][0] = 1;
    for (int i = 1; i <= M; i++)
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