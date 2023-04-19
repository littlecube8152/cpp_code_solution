#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

// _0, M1, O2
int N, g[30][30], p[30][30], vis[30][30][20000], win[20000], ans;
queue<int> qx, qy, qb;

// 012
// 345
// 678
void debug(int k)
{
    int m[9] = {};
    for (int i = 0; i < 9; i++)
    {
        m[i] = k % 3;
        k /= 3;
    }
    cout << m[0] << m[1] << m[2] << '\n';
    cout << m[3] << m[4] << m[5] << '\n';
    cout << m[6] << m[7] << m[8] << '\n';
    cout << '\n';
}

bool check(int k)
{
    int m[9] = {};
    for (int i = 0; i < 9; i++)
    {
        m[i] = k % 3;
        k /= 3;
    }
    if (m[0] == 1 && (m[1] + m[2] == 4 || m[4] + m[8] == 4 || m[3] + m[6] == 4))
        return true;
    if (m[2] == 1 && (m[1] + m[0] == 4 || m[4] + m[6] == 4 || m[5] + m[8] == 4))
        return true;
    if (m[6] == 1 && (m[0] + m[3] == 4 || m[4] + m[2] == 4 || m[7] + m[8] == 4))
        return true;
    if (m[8] == 1 && (m[5] + m[2] == 4 || m[4] + m[0] == 4 || m[7] + m[6] == 4))
        return true;
    if (m[3] == 1 && m[5] + m[4] == 4)
        return true;
    if (m[5] == 1 && m[3] + m[4] == 4)
        return true;
    if (m[1] == 1 && m[7] + m[4] == 4)
        return true;
    if (m[7] == 1 && m[1] + m[4] == 4)
        return true;
    return false;
}

int move(int k, int p, int c)
{
    int m[9] = {};
    for (int i = 0; i < 9; i++)
    {
        m[i] = k % 3;
        k /= 3;
    }
    if (!m[p])
        m[p] = c;
    for (int i = 8; i >= 0; i--)
    {
        k *= 3;
        k += m[i];
    }
    return k;
}

void push(int x, int y, int b)
{
    qx.push(x);
    qy.push(y);
    qb.push(b);
}

tuple<int, int, int> front()
{
    int x = qx.front(), y = qy.front(), b = qb.front();
    qx.pop();
    qy.pop();
    qb.pop();
    return make_tuple(x, y, b);
}

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            char c1, c2, c3;
            cin >> c1 >> c2 >> c3;
            if (c1 == 'B')
            {
                push(i, j, 0);
                vis[i][j][0] = 1;
            }
            else if (c1 == '#')
                g[i][j] = -1;
            else if (c1 != '.')
            {
                p[i][j] = (c2 - '1') * 3 + c3 - '1';
                g[i][j] = (c1 == 'M' ? 1 : 2);
            }
        }
    while (!qx.empty())
    {
        auto [x, y, b] = front();
        win[b] = check(b);
        if (!win[b])
            for (int dx = x - 1; dx <= x + 1; dx++)
                for (int dy = y - 1; dy <= y + 1; dy++)
                    if (abs(dx - x) + abs(dy - y) == 1 && g[dx][dy] >= 0)
                    {
                        int newb = (g[dx][dy] >= 1 ? move(b, p[dx][dy], g[dx][dy]) : b);
                        if (!vis[dx][dy][newb])
                        {
                            vis[dx][dy][newb] = 1;
                            push(dx, dy, newb);
                        }
                    }
    }
    for (int i = 0; i < 20000; i++)
        if (win[i])
        {
            ans++;
            //debug(i);
        }
    cout << ans << '\n';
}