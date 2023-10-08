#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, sz[10005], vis[10005];
vector<int> E[10005];

void dfs(int u)
{
    vis[u] = sz[u] = 1;
    for (auto v : E[u])
        if(!vis[v])
        {
            dfs(v);
            sz[u] += sz[v];
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    n++;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(0);
    int mx = 0, best = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> cc = {1, 0};
        for (int j : E[i])
            if(sz[j] > sz[i])
                cc.emplace_back(n - sz[i]);
            else
                cc.emplace_back(sz[j]);
        sort(cc.begin(), cc.end(), greater<int>());
        int sum = n * (n - 1) / 2 - (n - 1);
        for (auto j : cc)
            sum -= j * (j - 1) / 2;
        if(sum > mx)
        {
            mx = sum;
            best = sum -  cc[0] * cc[1];
        }
    }
    cout << mx << ' ' << best << '\n';
}