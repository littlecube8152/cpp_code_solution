#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, sz[300005], pre[300005], t = 0;
pii io[300005];
vector<int> E[300005], nE[300005];

void dfs(int u)
{
    io[u].F = ++t;
    sz[u] = 1;
    for (int v : E[u])
        if (pre[u] != v)
        {
            nE[u].emplace_back(v);
            pre[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    io[u].S = t;
}

signed main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    cin >> Q;
    cout << fixed << setprecision(10);
    for (int i = 1; i <= Q; i++)
    {
        int m, u, v;
        cin >> m >> u;

        set<int> st;
        bool has = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> v;
            if (u == v)
                has = 1;
            else if (!(io[u].F <= io[v].F && io[v].S <= io[u].S))
                st.insert(pre[u]);
            else
            {
                auto idx = *lower_bound(nE[u].begin(), nE[u].end(), v, [&](int i, int j)
                                        { return io[i].S < io[j].S; });
                st.insert(idx);
            }
        }
        if(has)
            cout << 0.0 << '\n';
        else if(st.size() > 1)
            cout << 1.0 << '\n';
        else
        {
            int k = *st.begin();
            cout << double(N) / (k == pre[u] ? sz[u] : N - sz[k]) << '\n';
        }
    }
}
