#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, ans[200005], C[200005], pre[200005], dis[200005];
vector<int> E[200005];

void dfs(int u)
{
    for (int v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
        }
}

signed main()
{
    cin >> N >> M;
    assert(N <= 2000);
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        cin >> C[i];
    for (int i = 1; i <= N; i++)
    {
        dis[i] = 0;
        pre[i] = 0;
        dfs(i);
        map<int, int> mp;
        set<int> st;
        mp[0] = 1;
        for (int j = 1; j <= N; j++)
            mp[dis[j]]++;
        for (int j = 1; j <= N; j++)
            if (mp[dis[j]] == 1)
                st.insert(C[j]);
        cout << st.size() << '\n';
    }
}