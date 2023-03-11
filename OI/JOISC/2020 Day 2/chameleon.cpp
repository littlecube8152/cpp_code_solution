#include "chameleon.h"
#include <vector>
using namespace std;

vector<int> two(int a, int b)
{
    return vector<int>{a, b};
}

vector<int> three(int a, int b, int c)
{
    return vector<int>{a, b, c};
}

void Solve(int N)
{
    vector<bool> vis(2 * N + 1, 0);
    for (int i = 1; i <= 2 * N; i++)
        if (!vis[i])
        {
            vector<int> v;
            bool flag = 0;
            for (int j = i + 1; j <= 2 * N; j++)
                if (Query(two(i, j)) == 1)
                    v.emplace_back(j);
            if (v.size() == 1)
            {
                Answer(i, v[0]);
                vis[i] = vis[v[0]] = 1;
                continue;
            }
            for (int j = 0; j < 3; j++)
                if (Query(two(v[j], v[(j + 1) % 3])) == 1)
                {
                    Answer(i, v[(j + 2) % 3]);
                    Answer(v[j], v[(j + 1) % 3]);
                    vis[i] = vis[v[0]] = vis[v[1]] = vis[v[2]] = 1;
                    flag = 1;
                }
            if (!flag)
            {
                int cnt[3] = {};
                for (int j = 0; j < 3; j++)
                    if (Query(three(i, v[j], v[(j + 1) % 3])) == 2)
                    {
                        // on no i go sadge
                    }
            }
        }
}
