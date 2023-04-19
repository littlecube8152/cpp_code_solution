#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

vector<int> E[40];
int vis[40], dis[40], deep[40];

void preproc(int u)
{
    vis[u] = 1;
    for (int v : E[u])
        if (!vis[v])
        {
            dis[v] = dis[u] + 1;
            preproc(v);
            deep[u] = max(deep[u], deep[v]);
        }
    vis[u] = 0;
    sort(E[u].begin(), E[u].end(), [&](int i, int j)
         { return deep[i] < deep[j]; });
}

string dfs(int u)
{
    vis[u] = 1;
    string s;
    for (int v : E[u])
        if (!vis[v])
        {
            s = s + "0";
            s = s + dfs(v);
            s = s + "1";
        }
    vis[u] = 0;
    return s;
}

string root(int r, int n)
{
    for(int i = 1; i <= n; i++)
        dis[i] = deep[i] = 0;
    preproc(r);
    string s = dfs(r);
    s = s.substr(1);
    while(!s.empty() && s.back() == '1')
        s.pop_back();
    return s;
}

string Black(int n, vector<pair<int, int>> edge)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        E[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        auto [u, v] = edge[i];
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    string s = root(1, n);
    for(int i = 2; i <= n; i++)
    {
        string t = root(i, n);
        if(t.size() < s.size())
            s = t;
    }
    return s;
}