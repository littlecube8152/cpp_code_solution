#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q, grid[4500][4500], t[1005];

signed main()
{
    cin >> n >> q;
    vector<pii> cur, nxt;
    for (int i = 1; i <= n; i++)
    {
        int p, q;
        cin >> p >> q;
        p += 2023;
        q += 2023;
        grid[p][q] = 1;
        cur.emplace_back(pii(p, q));
    }
    for (int i = 1; i <= q; i++)
    {
        int s;
        cin >> s;
        t[s] = 1;
    }
    for (int i = 0; i <= 1000; i++)
    {
        if (t[i])
        {
            cout << cur.size() << '\n';
            if (i <= 5)
            {
                for (int x = -6; x <= 6; x++)
                    for (int y = -20; y <= 20; y++)
                        cout << grid[x + 2023][y + 2023] << " \n"[y == 20];
                cout << '\n';
            }
        }

        for (auto [x, y] : cur)
            grid[x][y] = 2;

        for (auto [x, y] : cur)
        {
            for (auto [dx, dy] : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
                if (grid[x + dx][y + dy] == 0)
                {
                    grid[x + dx][y + dy] = 1;
                    nxt.emplace_back(pii(x + dx, y + dy));
                }
        }
        cur.clear();
        cur.swap(nxt);
    }
}