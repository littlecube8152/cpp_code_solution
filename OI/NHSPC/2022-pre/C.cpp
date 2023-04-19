#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, a[1000006], vis[1000006];
vector<pii> E[1000006][3];
vector<int> sol;

int direct(int a, int b)
{
    if (a == b)
        return 1;
    return a < b ? 2 : 0;
}

// dir = {0: dec, 1: mid, 2: inc}
const vector<int> decr = {0, 1, 2}, inc = {2, 1, 0};
void dfs(int u, int dir)
{
    if (dir == 2)
    {
        for (auto k : inc)
            for (; !E[u][k].empty();)
                if (!vis[E[u][k].back().S])
                {
                    vis[E[u][k].back().S] = 1;
                    int v = E[u][k].back().F;
                    E[u][k].pop_back();
                    dfs(v, direct(u, v));
                }
                else
                    E[u][k].pop_back();
    }
    else if (dir == 0)
    {
        for (auto k : decr)
            for (; !E[u][k].empty();)
                if (!vis[E[u][k].back().S])
                {
                    vis[E[u][k].back().S] = 1;
                    int v = E[u][k].back().F;
                    E[u][k].pop_back();
                    dfs(v, direct(u, v));
                }
                else
                    E[u][k].pop_back();
    }
    else
    {
        int cur = (!E[u][0].empty() || !E[u][2].empty() ? (E[u][0].size() >= E[u][2].size() ? 0 : 2) : 1);
        for (; !E[u][cur].empty();)
        {
            if (!vis[E[u][cur].back().S])
            {
                vis[E[u][cur].back().S] = 1;
                int v = E[u][cur].back().F;
                E[u][cur].pop_back();
                dfs(v, direct(u, v));
            }
            else
                E[u][cur].pop_back();
            cur = (!E[u][0].empty() || !E[u][2].empty() ? (E[u][0].size() >= E[u][2].size() ? 0 : 2) : 1);
        }
    }
    sol.emplace_back(u);
}

void addedge(int u, int v, int i)
{
    if (v < u)
        E[u][0].emplace_back(pii(v, i));
    else if (u == v)
        E[u][1].emplace_back(pii(v, i));
    else
        E[u][2].emplace_back(pii(v, i));
}

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i < N; i++)
    {
        addedge(a[i], a[i + 1], i);
        addedge(a[i + 1], a[i], i);
    }
    dfs(a[1], 1);
    reverse(sol.begin(), sol.end());
    for (auto i : sol)
        cout << i << ' ';
    cout << '\n';
}