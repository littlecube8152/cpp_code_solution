#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M;
char grid[30][30];
int dp[55][55][55][55], vis[55][55][55][55];

int calc(int l, int r, int u, int d)
{
    if (r < l || d < u)
        return 0;
    if (!vis[l][r][u + M][d + M])
    {
        bitset<60> b;
        b.set();
        for (int p = l; p <= r; p += 2)
            for (int m = u; m <= d; m += 2)
            {
                int x = (p + m) / 2, y = (p - m) / 2;
                if (x <= 0 || x > N || y <= 0 || y > M)
                    continue;
                if (grid[x][y] == 'R')
                    b[calc(l, p - 2, u, d) ^ calc(p + 2, r, u, d)] = 0;
                else if (grid[x][y] == 'B')
                    b[calc(l, r, u, m - 2) ^ calc(l, r, m + 2, d)] = 0;
                else
                    b[calc(l, p - 2, u, m - 2) ^ calc(p + 2, r, u, m - 2) ^ calc(l, p - 2, m + 2, d) ^ calc(p + 2, r, m + 2, d)] = 0;
            }
        vis[l][r][u + M][d + M] = 1;
        dp[l][r][u + M][d + M] = b._Find_first();
        // cerr << l << ' ' << r << ' ' << u << ' ' << d << " : " << b._Find_first() << '\n';
    }
    return dp[l][r][u + M][d + M];
}

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> grid[i][j];
    int sg = 0;
    for (int p = 0; p < 2; p++)
    {
        int l = 1e9, r = -1e9, u = 1e9, d = -1e9;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if ((i + j) % 2 == p)
                    l = min(l, i + j), r = max(r, i + j), u = min(u, i - j), d = max(d, i - j);
        sg ^= calc(l, r, u, d);
        // cerr << calc(l, r, u, d) << '\n';
    }
    cout << (sg ? "W\n" : "L\n");
}