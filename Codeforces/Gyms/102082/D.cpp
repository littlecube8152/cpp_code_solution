#include <bits/stdc++.h>
#define ll long long
#define pii pair<short, short>
#define F first
#define S second
using namespace std;

int n, m, A[4005][2], B[4005][2], dp[4005][4005], vis[4005][4005];
vector<pii> dis[8005];
string s, t;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    n = s.size(), m = t.size();
    for (int i = 0; i <= n + 1; i++)
        A[i][0] = A[i][1] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        int c = s[i] - '0';
        A[i][c] = i;
        A[i][c ^ 1] = A[i + 1][c ^ 1];
    }
    for (int i = 0; i <= m + 1; i++)
        B[i][0] = B[i][1] = m;
    for (int i = m - 1; i >= 0; i--)
    {
        int c = t[i] - '0';
        B[i][c] = i;
        B[i][c ^ 1] = B[i + 1][c ^ 1];
    }

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                int x = A[i][k] + 1, y = B[j][k] + 1;

                if (dp[i][j] + 1 <= dp[x][y])
                    dp[x][y] = dp[i][j] + 1;
            }
            if (dp[i][j] <= 5000)
                dis[dp[i][j]].emplace_back(pii(i, j));
        }
    string u;
    int l = dp[n + 1][m + 1];
    vector<pii> nxt[2], cur = {pii(n + 1, m + 1)};
    cerr << l << '\n';
    int t = 0;
    while (l)
    {
        l--;
        for (auto [i, j] : cur)
            vis[i][j] = 1;
        for (auto [i, j] : dis[l])
        {
            for (int k = 0; k <= 1; k++)
            {
                int x = A[i][k] + 1, y = B[j][k] + 1;

                if (vis[x][y] == 1)
                    nxt[k].emplace_back(pii(i, j));
            }
        }
        for (auto [i, j] : cur)
            vis[i][j] = 0;
        if (!nxt[0].empty())
            cur = nxt[0], cout << 0;
        else
            cur = nxt[1], cout << 1;
        nxt[0].clear(), nxt[1].clear();
    }
    cout << '\n';
}