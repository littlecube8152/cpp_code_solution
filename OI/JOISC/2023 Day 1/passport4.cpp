#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

short N, Q, L[2505], R[2505], dp[2505][2505];
vector<short> same[2505][2505], sameR[2505][2505], sameL[2505][2505];
struct segTree
{
    short seg[1 << 13];
    void init()
    {
        for (short i = 0; i < 8192; i++)
            seg[i] = N + 1;
    }
    void modify(short mL, short mR, short val, short i = 1, short L = 1, short R = N)
    {
        if (mL <= L && R <= mR)
            seg[i] = min(seg[i], val);
        else if (mR < L || R < mL)
            return;
        else
        {
            short mid = (L + R) / 2;
            modify(mL, mR, val, i << 1, L, mid);
            modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        }
    }
    short query(short pos, short i = 1, short L = 1, short R = N)
    {
        if (L == R)
            return seg[i];
        else
        {
            short mid = (L + R) / 2;
            if (pos <= mid)
                return min(seg[i], query(pos, i << 1, L, mid));
            else
                return min(seg[i], query(pos, i << 1 | 1, mid + 1, R));
        }
    }
} Ltree[2505], Rtree[2505];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (short i = 0; i <= N + 1; i++)
        for (short j = 0; j <= N + 1; j++)
            dp[i][j] = N + 1;
    for (short i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i];
        same[L[i]][R[i]].emplace_back(i);
        for (short j = 1; j < L[i]; j++)
            sameR[j][R[i]].emplace_back(i);
        for (short j = R[i] + 1; j <= N; j++)
            sameL[L[i]][j].emplace_back(i);
        Ltree[i].init();
        Rtree[i].init();
    }
    dp[1][N] = 0;
    for (short i = 1; i <= N; i++)
        for (short j = N; j >= i; j--)
        {
            dp[i][j] = min({dp[i][j], Ltree[i].query(j), Rtree[j].query(i)});
            for (short k : same[i][j])
            {
                for (short l = i; l <= k; l++)
                    Ltree[l].modify(k, j, dp[i][j] + 1);
            }
            for (short k : sameR[i][j])
            {
                if (k <= j - 1)
                    Ltree[i].modify(k, j - 1, dp[i][j] + 1);
            }
            for (short k : sameL[i][j])
            {
                if (i + 1 <= k)
                    Rtree[j].modify(i + 1, k, dp[i][j] + 1);
            }
        }
    cin >> Q;
    for (short i = 1; i <= Q; i++)
    {
        short q;
        cin >> q;
        cout << (dp[q][q] > N ? -1 : dp[q][q]) << '\n';
    }
}