#include <bits/stdc++.h>
#define ll long long
using namespace std;

int h, w, graph[105][105];
int visit[105][105];

int bs(int L, int R)
{
    if (L == R)
        return R;
    int mid = (L + R) / 2;
    queue<pair<int, int>> q;
    int vis[105][105] = {{0}};
    q.push(make_pair(0, 0));
    vis[0][0] = 1;
    while (!q.empty())
    {
        for (pair<int, int> i : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
        {
            if (h > q.front().first + i.first && q.front().first + i.first >= 0 && w > q.front().second + i.second && q.front().second + i.second >= 0)
                if (!vis[q.front().first + i.first][q.front().second + i.second])
                    if (abs(graph[q.front().first][q.front().second] - graph[q.front().first + i.first][q.front().second + i.second]) <= mid)
                    {
                        q.push(make_pair(q.front().first + i.first, q.front().second + i.second));
                        vis[q.front().first + i.first][q.front().second + i.second] = 1;
                    }
        }
        q.pop();
    }
    if (vis[h - 1][w - 1])
        return bs(L, mid);
    else
        return bs(mid + 1, R);
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> graph[i][j];
    cout << bs(0, 100000) << '\n';
}