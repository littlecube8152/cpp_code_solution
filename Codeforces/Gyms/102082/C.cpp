#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int r, s, n, out[505][2], stop[505][2];
deque<int> q[505][2], c;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> r >> s >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x = r - x;
        if (y <= s)
            q[x][0].emplace_back(s - y + 1);
        else
            q[x][1].emplace_back(y - s);
    }
    for (int i = 0; i < r; i++)
        for (int k = 0; k <= 1; k++)
        {
            sort(q[i][k].begin(), q[i][k].end());
            for (int j = 0; j < q[i][k].size(); j++)
                if (q[i][k][j] == j + 1)
                    stop[i][k] = j + 1;
                else
                    break;
        }
    c.resize(r, 0);
    for (int t = 1; t <= 2 * r * s + 5; t++)
    {
        if (c.front() == 1)
            n--;
        c.pop_front(), c.push_back(0);
        for (int i = r - 1; i >= 0; i--)
        {
            int &mv = c[i];
            for (int k = 0; k <= 1; k++)
                if (!mv && stop[i][k])
                {
                    stop[i][k]--;
                    q[i][k].pop_front();
                    mv = 1;
                    out[i][k]++;
                }
                else
                {
                    out[i][k]++;
                    for (int j = stop[i][k]; j < q[i][k].size(); j++)
                        if (q[i][k][j] - out[i][k] == j + 1)
                            stop[i][k] = j + 1;
                        else
                            break;
                }
        }
        if(n == 0)
        {
            cout << t << '\n';
            return 0;
        }
    }
}