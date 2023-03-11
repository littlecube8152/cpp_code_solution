#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M;
pii pre[1005][1005];
char c[1005][1005];
const vector<pii> v = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> c[i][j];
    pii s, e;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (c[i][j] == '#')
            {
                int cnt = 0;
                for (auto [di, dj] : v)
                    if (c[i + di][j + dj] == '#')
                        cnt++;
                if (cnt == 1)
                {
                    if (s == pii(0, 0))
                        s = pii(i, j);
                    else
                        e = pii(i, j);
                }
                else if (cnt == 2)
                {
                    for (auto [di, dj] : v)
                        if (c[i + di][j + dj] == '.')
                            c[i + di][j + dj] = 'X';
                }
            }
    queue<pii> q;


    pre[s.F][s.S] = pii(-1, -1);
    c[e.F][e.S] = '.';
    q.push(s);
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : v)
            if (c[x + dx][y + dy] == '.' && !(pii(x, y) == s && pii(x + dx, y + dy) == e) && pre[x + dx][y + dy] == pii(0, 0))
            {
                pre[x + dx][y + dy] = pii(x, y);
                q.push(pii(x + dx, y + dy));
            }
    }
    while (e != pii(-1, -1))
    {
        assert(e.F != 0);
        c[e.F][e.S] = '#';
        e = pre[e.F][e.S];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << (c[i][j] == 'X' ? '.' : c[i][j]);
        cout << '\n';
    }
}