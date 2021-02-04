#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
char _map[1005][1005] = {{0}};
ll val[1005][1005] = {{0}};
bool vis[1005][1005] = {{0}};
ll n, m, r = 0;
int main()
{
    fast;
    queue<pii> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> _map[i][j];
            if (_map[i][j] == '9')
            {
                q.push(make_pair(i, j));
                val[i][j] = 1;
            }
        }
    while (!q.empty())
    {
        if (_map[q.front().first][q.front().second] == '0')
        {
            r += val[q.front().first][q.front().second];
            q.pop();
            continue;
        }
        for (pii d : vector<pii>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
            if (_map[q.front().first + d.first][q.front().second + d.second] - _map[q.front().first][q.front().second] == -1)
            {
                val[q.front().first + d.first][q.front().second + d.second] += val[q.front().first][q.front().second];
                if (!vis[q.front().first + d.first][q.front().second + d.second])
                {
                    q.push(make_pair(q.front().first + d.first, q.front().second + d.second));
                    vis[q.front().first + d.first][q.front().second + d.second] = 1;
                }
            }
        q.pop();
    }
    cout << r << '\n';
}