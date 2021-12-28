#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

bool graph[1500][1500];
vector<int> edge[1500];
int N, T, id[1500][1500], L = 0, R = 0, match[1500], vis[1500] = {};

bool dfs(int k)
{
    vis[k] = 1;
    for (int j : edge[match[k]])
        if (!vis[j])
        {
            if (match[j] == 0 || dfs(j))
            {
                match[j] = match[k];
                return true;
            }
        }
    return false;
}

int main()
{
    cin >> N >> T;
    for (int i = 1; i <= T; i++)
    {
        int x, y;
        cin >> x >> y;
        id[x][y] = -1;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (id[i][j] != -1)
            {
                if ((i + j) & 1)
                    id[i][j] = ++L;
                else
                    id[i][j] = ++R;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (id[i][j] != -1)
            {
                for (pair<int, int> d : vector<pair<int, int>>{{1, -2}, {2, -1}, {1, 2}, {2, 1}})
                {
                    if (0 <= i + d.F && i + d.F < N &&
                        0 <= j + d.S && j + d.S < N &&
                        id[i + d.F][j + d.S] != -1)
                    {
                        if ((i + j) & 1)
                        {
                            graph[id[i][j]][id[i + d.F][j + d.S]] = 1;
                            edge[id[i][j]].emplace_back(id[i + d.F][j + d.S]);
                        }
                        else
                        {
                            graph[id[i + d.F][j + d.S]][id[i][j]] = 1;
                            edge[id[i + d.F][j + d.S]].emplace_back(id[i][j]);
                        }
                    }
                }
            }

    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= R; j++)
            vis[j] = 0;
        for (int j : edge[i])
        {
            if (match[j] == 0 || dfs(j))
            {
                match[j] = i;
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= R; i++)
        if(match[i] != 0)
            cnt++;
    cout << L + R - cnt << '\n';
}
