#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, A[305], B[305], sumA;

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
    assert(M <= 2);
    fail(K > M);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        fail(A[i] < K);
        sumA += A[i];
    }
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    int ans = 1e9;
    if (K == 2)
    {
        fail(B[1] < N || B[2] < N || B[1] + B[2] < sumA);
        cout << B[1] + B[2] - sumA << '\n';
    }
    else
    {
        if (B[1] + B[2] - sumA >= 0)
            ans = min(ans, B[1] + B[2] - sumA);
        if (B[2] - sumA >= 0)
            ans = min(ans, B[2] - sumA);
        if (B[1] - sumA >= 0)
            ans = min(ans, B[1] - sumA);
        fail(ans >= 1e8);
        cout << ans << '\n';
    }
}