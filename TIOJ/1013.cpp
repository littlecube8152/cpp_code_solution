/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string g[10] = {"*****************",
                "*...*.......**..*",
                "**..*....*.*.*..*",
                "*......*.**.**.**",
                "*..**...**..**.**",
                "**.....**..*.*..*",
                "*....*..........*",
                "*.....****.*...**",
                "****.*.*........*",
                "*****************"};
int n, m, t, fx, fy, sx, sy, ex, ey, graph[10][17];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue<pii> q;
signed main()
{
    fast;
    cin >> fx >> fy;
    graph[fx][fy] = -1;
    q.push(make_pair(fx, fy));
    cin >> t;
    cin >> sx >> sy >> ex >> ey;
    g[ex][ey] = '*';

    while (!q.empty())
    {
        //cout << q.front().F << " " << q.front().S << " " << graph[q.front().F][q.front().S] << '\n';
        for (int i = 0; i < 4; i++)
            if (g[q.front().F + dx[i]][q.front().S + dy[i]] == '.' && graph[q.front().F + dx[i]][q.front().S + dy[i]] == 0)
            {
                graph[q.front().F + dx[i]][q.front().S + dy[i]] = graph[q.front().F][q.front().S] - 1;
                q.push(make_pair(q.front().F + dx[i], q.front().S + dy[i]));
            }
        q.pop();
    }
    while (!q.empty())
        q.pop();

    if (-graph[sx][sy] >= t)
        q.push(make_pair(sx, sy));
    graph[sx][sy] = t;
    graph[ex][ey] = -10000000000;
    g[ex][ey] = '.';

    while (!q.empty())
    {
        if (q.front() == make_pair(ex, ey))
        {
            cout << graph[ex][ey] - t << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++)
            if (g[q.front().F + dx[i]][q.front().S + dy[i]] == '.' && ((graph[q.front().F][q.front().S] + 1 < abs(graph[q.front().F + dx[i]][q.front().S + dy[i]])) || graph[q.front().F + dx[i]][q.front().S + dy[i]] == 0))
            {
                graph[q.front().F + dx[i]][q.front().S + dy[i]] = graph[q.front().F][q.front().S] + 1;
                q.push(make_pair(q.front().F + dx[i], q.front().S + dy[i]));
            }
        q.pop();
    }
    //for (int i = 0; i < 10; i++)
    //    for (int j = 0; j < 17; j++)
    //        cout << graph[i][j] << " \n"[j == 16];
    cout << "Help!\n";
}
