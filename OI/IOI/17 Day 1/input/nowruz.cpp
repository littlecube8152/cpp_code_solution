#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, m, k, vis[1030][1030], best[1030][1030], kstar;
char g[1030][1030];

mt19937 rd(10);
int gen(int p)
{
    return rd() % p + 1;
}
bool prob(double d)
{
    return (rd() % 100000001) / 100000000.0 <= d;
}

int checkadj(int i, int j)
{
    if (g[i][j] != '.')
        return 1e9;
    return vis[i - 1][j] + vis[i + 1][j] + vis[i][j - 1] + vis[i][j + 1];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    int iter = 30;
    while (iter--)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                vis[i][j] = 0;

        int x = 0, y = 0;
        while (g[x][y] != '.')
            x = gen(n), y = gen(m);

        vis[x][y] = 1;
        vector<pii> pos;
        pos.emplace_back(pii(x, y));

        int t = (n + m) * 4;
        while (t--)
        {
            // cerr << t << ' ';
            shuffle(pos.begin(), pos.end(), rd);
            vector<pii> nxt;
            for (auto [x, y] : pos)
            {
                bool flag = 0;
                for (int dx = -1; dx <= 1; dx++)
                    for (int dy = -1; dy <= 1; dy++)
                        if (abs(dx) + abs(dy) == 1)
                            if (checkadj(x + dx, y + dy) == 1)
                            {
                                // flag = 1;
                                vis[x + dx][y + dy] = 1;
                                nxt.emplace_back(pii(x + dx, y + dy));
                            }
                if (flag)
                    nxt.emplace_back(pii(x, y));
            }

            pos = nxt;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j] && checkadj(i, j) == 1)
                    cnt++;
        if (cnt > kstar)
        {
            kstar = cnt;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    best[i][j] = vis[i][j];
        }
    }
    cerr << fixed << setprecision(5) << double(kstar) / k * 10.0 << " + ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '#')
                cout << '#';
            else if (best[i][j])
                cout << '.';
            else
                cout << 'X';
        cout << '\n';
    }
}
