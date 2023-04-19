#include <bits/stdc++.h>
using namespace std;

int N, Q, best[805][805], ndx;
char edge[805][805];

signed main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            cin >> edge[i][j];
    for (int j = 1; j <= N; j++)
    {
        vector<int> sa, rk(N + 1), lcp;
        sa.emplace_back(j);
        rk[j] = 0;
        sa.emplace_back(-1);
        for (int i = j - 1; i >= 1; i--)
        {
            best[i][j] = i + 1;
            for (int k = i + 2; k <= j; k++)
                if (make_pair(edge[i][k], rk[k]) < make_pair(edge[i][best[i][j]], rk[best[i][j]]))
                    best[i][j] = k;

            int pos = 0, cp = 0;
            for ()
        }
    }
    while (Q--)
    {
        int i, j, k, cur, len = 0;
        cin >> i >> j >> k;
        cur = i;
        while (cur != j)
            len++, cur = best[cur][j];
        cout << len << ' ';
        k = len - k;
        len = 0;
        cur = i;
        while (cur != j)
        {
            len++;
            if (len > k)
                cout << edge[cur][best[cur][j]];
            cur = best[cur][j];
        }
        cout << '\n';
    }
}