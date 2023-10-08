#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, ans, vis[505][505];
char g[505][505];

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
            if(!vis[i + x][j + y] && g[i + x][j + y] == '#')
                dfs(i + x, j + y);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && g[i][j] == '#')
            {
                ans++;
                dfs(i, j);
            }
    cout << ans << '\n';
}