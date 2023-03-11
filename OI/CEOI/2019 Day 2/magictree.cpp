#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k, p[100005], d[100005], sz[100005];
ll w[100005];
vector<int> E[100005];
map<int, ll> mp[100005];

void dfs(int u)
{
    sz[u] = 1;
    for (int v : E[u])
    {
        dfs(v);
        sz[u] += sz[v];
    }
    sort(E[u].begin(), E[u].end(), [&](int i, int j)
         { return sz[i] > sz[j]; });
    for (int i = 0; i < E[u].size(); i++)
    {
        int v = E[u][i];
        if (i == 0)
            mp[u].swap(mp[v]);
        else
        {
            for(auto [p, val] : mp[v])
                mp[u][p] += val;
            mp[v].clear();
        }
    }
    if(w[u])
    {
        ll r = w[u];
        mp[u][d[u]] += w[u];
        auto iter = mp[u].upper_bound(d[u]);
        while(r > 0 && iter != mp[u].end())
        {
            ll cur = iter->second;
            if(r >= cur)
                iter = mp[u].erase(iter);
            else
                iter->second -= r;
            r -= cur;
        }
    }
}

signed main()
{
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        E[p[i]].emplace_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v;
        cin >> d[v] >> w[v];
    }
    dfs(1);
    ll ans = 0;
    for(auto [p, v] : mp[1])
        ans += v;
    cout << ans << '\n';
}