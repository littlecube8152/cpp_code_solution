#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, mxC;
double ans = 1e15, dp[505][505], res[505];
pll A[505];

double calc(int i)
{
    for (int k = i; k >= 0; k--)
        for (int l = K - i; l >= 0; l--)
            dp[k][l] = 1e15;
    dp[0][0] = 0;
    for (int j = 1; j <= N; j++)
        for (int k = i; k >= 0; k--)
            for (int l = K - i; l >= 0; l--)
            {
                if (k > 0)
                    dp[k][l] = min(dp[k][l], dp[k - 1][l] + double(A[j].S) / double(k));
                if (l > 0)
                    dp[k][l] = min(dp[k][l], dp[k][l - 1] + double(A[j].F) / double(i + 1));
            }
    return dp[i][K - i];
}

signed main()
{
    cin >> N >> K;
    mxC = N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i].F >> A[i].S;
        if (A[i].S == -1)
            mxC--, A[i].S = 1e15;
    }
    sort(A + 1, A + 1 + N, [&](pll p1, pll p2)
         { return pll{p1.S, p1.F} < pll{p2.S, p2.F}; });
    int L = 0, R = min(K, mxC);
    int lmid = floor(L * 0.618 + R * 0.382), rmid = floor(L * 0.382 + R * 0.618);
    while (R - L > 9)
    {

        double lans = calc(lmid), rans = calc(rmid);
        if (lans <= rans)
        {
            R = rmid;
            rmid = lmid;
            lmid = floor(L * 0.618 + R * 0.382);
        }
        else
        {
            L = lmid;
            lmid = rmid;
            rmid = floor(L * 0.382 + R * 0.618);
        }
    }
    for (int i = L; i <= R; i++)
        ans = min(ans, calc(i));
    cout << fixed << setprecision(10) << ans << '\n';
}