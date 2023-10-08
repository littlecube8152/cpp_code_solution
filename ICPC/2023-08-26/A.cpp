#include <bits/stdc++.h>
using namespace std;
#define double long double
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

/*
6 7
 _ _ _ _ _ _ _
| |  _ _|  _  |
| | |_ _| |_| |
| |_ _ _|  _ _|
| |  _ _| |   |
| | |_ _| |   |
|_|_ _ _|_|_ _|
6 3 7 2 2 2

0 1 1 1 2 2 2
0 1 3 3 2 4 2
0 1 1 1 2 2 2
0 5 5 5 2 6 6
0 5 7 7 2 6 6
0 5 5 5 2 6 6
*/

const int mod = 1'000'000'007;
char grid[100][100];
int n, m, k, color[30][30], occ[30], vis[30][30], row[30][30], up[30], down[30];
ll cur[1 << 20], nxt[1 << 20];

void dfs(int x, int y, int c)
{
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    color[x][y] = c;
    row[c][x]++;
    up[c] = min(up[c], x);
    down[c] = max(down[c], x);
    if (grid[x][y * 2] != '_')
        dfs(x + 1, y, c);
    if (grid[x - 1][y * 2] != '_')
        dfs(x - 1, y, c);
    if (grid[x][y * 2 - 1] != '|')
        dfs(x, y - 1, c);
    if (grid[x][y * 2 + 1] != '|')
        dfs(x, y + 1, c);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    string s;
    getline(cin, s);
    for (int i = 0; i <= n; i++)
    {
        getline(cin, s);
        for (int j = 1; j <= 2 * m + 1; j++)
            grid[i][j] = s[j - 1];
    }

    for (int i = 1; i <= n; i++)
        cin >> occ[i];
    for (int i = 0; i <= 20; i++)
        up[i] = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j])
                dfs(i, j, k++);

    nxt[(1 << k) - 1] = 1;
    for (int i = n; i >= 1; i--)
    {
        for (int mask = 0; mask < (1 << k); mask++)
            cur[mask] = nxt[mask];

        for (int j = 0; j < k; j++)
            for (int mask = 0; mask < (1 << k); mask++)
                if (!((mask >> j) & 1))
                    cur[mask] = (cur[mask] + cur[mask ^ (1 << j)]) % mod;

        for (int mask = 0; mask < (1 << k); mask++)
        {
            int tot = 0;
            bool able = 1;
            for (int j = 0; j < k; j++)
                if ((mask >> j) & 1)
                {
                    if (i < up[j])
                        able = 0;
                    tot += row[j][i];
                }
                else
                {
                    if (i > down[j])
                        able = 0;
                }

            if (able && (tot == occ[i] || occ[i] == -1))
            {
                bitset<8> b = mask;
                nxt[mask] = cur[mask];
            }
            else
                nxt[mask] = 0;
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << k); mask++)
    {
        ans = (ans + nxt[mask]) % mod;
    }
    cout << ans << '\n';
}