#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, pre[500005], sz[500005], cnt;
vector<int> E[500005], leaf;
vector<pii> ans;

void dfs(int u)
{
    sz[u] = (E[u].size() == 1);
    for (auto v : E[u])
        if(pre[u] != v)
        {
            pre[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
}

void collect(int u)
{
    if(E[u].size() == 1)
        leaf.emplace_back(u);
    for (auto v : E[u])
        if(pre[u] != v)
        {
            pre[v] = u;
            collect(v);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        bool flag = (sz[1] - sz[i] <= sz[1] / 2);
        for(auto j : E[i])
            if(pre[i] != j && sz[j] > sz[1] / 2)
                flag = 0;
        if(flag)
            c = i;
    }
    pre[c] = 0;
    collect(c);
    for (int i = 0; i < sz[1] / 2; i++)
        ans.emplace_back(pii(leaf[i], leaf[i + (sz[1] + 1) / 2]));
    if(sz[1] & 1)
        ans.emplace_back(pii(c, leaf[sz[1] / 2]));
    cout << ans.size() << '\n';
    for(auto [i, j] : ans)
        cout << i << ' ' << j << '\n';
}