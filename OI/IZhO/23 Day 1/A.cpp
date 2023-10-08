#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int dpl[2505][2505], dpr[2505][2505];
int froml[2505][2505], fromr[2505][2505];
int n, m, ans, g[2505][2505], sum[2505][2505], last[2505];

int query(int u, int d, int l, int r)
{
    return (sum[d][r] - (l ? sum[d][l - 1] : 0) - (u ? sum[u - 1][r] : 0) + (u && l ? sum[u - 1][l - 1] : 0));
}

int getDP(int i, int l, int r)
{
    int res = 0;
    if(r < l)
        return 0;
    if (froml[i][r] == l)
        res = max(res, dpl[i][r]);
    if (fromr[i][l] == r)
        res = max(res, dpr[i][l]);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c;
        g[i][0] = g[i][m + 1] = -1;
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == 'X')
                g[i][j] = -1;
            else
                g[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = g[i][j] + (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) - (i && j ? sum[i - 1][j - 1] : 0);
    for (int i = 1; i <= n; i++)
    {
        for (int l = 0, r = 0; l <= m; l = r)
        {
            r = l + 1;
            while (g[i][r] >= 0)
                r++;
            if (r - l == 1)
                continue;
            // calc dp[i][l+1:j] and dp[i][j:r-1]
            {
                int choice = 0, row = 0, col = l;
                for (int j = l + 1; j <= r - 1; j++)
                {
                    if (last[j] > row)
                    {
                        row = last[j];
                        choice = getDP(row, l + 1, j - 1);
                        col = j;
                    }
                    else if (last[j] == row)
                    {
                        choice = max(choice, getDP(row, col + 1, j - 1));
                        col = j;
                    }
                    dpl[i][j] = query(row + 1, i, l + 1, j) + max(choice, getDP(row, col + 1, j));
                    froml[i][j] = l + 1;
                }
            }

            {
                int choice = 0, row = 0, col = r;
                for (int j = r - 1; j >= l + 1; j--)
                {
                    if (last[j] > row)
                    {
                        row = last[j];
                        choice = getDP(row, j + 1, r - 1);
                        col = j;
                    }
                    else if (last[j] == row)
                    {
                        choice = max(choice, getDP(row, j + 1, col - 1));
                        col = j;
                    }
                    dpr[i][j] = query(row + 1, i, j, r - 1) + max(choice, getDP(row, j, col - 1));
                    fromr[i][j] = r - 1;
                }
            }
        }
        for (int j = 0; j <= m + 1; j++)
            if (g[i][j] < 0)
                last[j] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max({ans, dpl[i][j], dpr[i][j]});
    cout << ans << '\n';
}