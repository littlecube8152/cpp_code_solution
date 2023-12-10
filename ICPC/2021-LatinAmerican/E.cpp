#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll S[3005], D[3005], dp[3005][3005][2];

struct seg
{
    ll seg[8200];
    void modify(int pos, ll val, int i = 1, int L = 0, int R = N + 1)
    {
        if (L == R)
            seg[i] = val;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1,     L, mid);
            else
                modify(pos, val, i << 1 | 1, mid + 1, R);
            seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    ll query(int qL, int qR, int i = 1, int L = 0, int R = N + 1)
    {
        if (qL <= L && R <= qR)
            return seg[i];
        else if (R < qL || qR < L)
            return (ll)1e18;
        else
        {
            int mid = (L + R) / 2;
            return min(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} seg[3005][2];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 2; i <= N; i++)
        cin >> S[i], S[i] += S[i - 1];
    S[N + 1] = S[N];
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    for (int i = 0; i <= N; i++)
    {
        int F;
        cin >> F;
        dp[i][i + 1][0] = dp[i][i + 1][1] = F;
    }

    for (int l = 1; l <= N + 1; l++)
        for (int i = 0; i + l <= N + 1; i++)
            for (int k = 0; k <= 1; k++)
            {
                int j = i + l;
                int L = i, R = j - 1;
                while (L < R)
                {
                    int mid = (L + R + 1) / 2;
                    if (dp[i][mid][1] < dp[mid][j][0])
                        L = mid;
                    else
                        R = mid - 1;
                }
                if (l >= 2)
                {
                    dp[i][j][k] = min(seg[i][k].query(L + 1, j - 1) + (!k ? -S[i] : S[j]),
                                      seg[j][k].query(i + 1, L) + (!k ? -S[i] : S[j]));
                }
                if (k == 1)
                {
                    seg[i][0].modify(j, dp[i][j][k] + S[j] + D[j]);
                    seg[i][1].modify(j, dp[i][j][k] - S[j] + D[j]);
                }
                else
                {
                    seg[j][0].modify(i, dp[i][j][k] + S[i] + D[i]);
                    seg[j][1].modify(i, dp[i][j][k] - S[i] + D[i]);
                }
            }

    cout << dp[0][N + 1][0] << '\n';
}
