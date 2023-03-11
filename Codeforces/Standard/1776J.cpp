#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, p, c[205], d[205][205], ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 1; j <= 2 * n; j++)
            d[i][j] = (i == j ? 0 : 5000);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (c[u] != c[v])
        {
            d[u * 2 - 1][v * 2] = 1;
            d[u * 2][v * 2 - 1] = 1;
            d[v * 2][u * 2 - 1] = 1;
            d[v * 2 - 1][u * 2] = 1;
        }
        else
        {
            d[u * 2 - 1][v * 2 - 1] = 1;
            d[v * 2 - 1][u * 2 - 1] = 1;
            d[u * 2][v * 2] = 1;
            d[v * 2][u * 2] = 1;
        }
    }
    for (int k = 1; k <= 2 * n; k++)
        for (int i = 1; i <= 2 * n; i++)
            for (int j = 1; j <= 2 * n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            // cout << i << " -> " << j << " " << d[i * 2][j * 2] << '\n';
            // cout << i << " -> " << j << "* " << d[i * 2][j * 2 - 1] << '\n';
            for (int k = 0; k <= p; k++)
                ans = max(ans, min(d[i * 2][j * 2] + k, d[i * 2][j * 2 - 1] + p - k));
        }
    cout << ans << '\n';
}