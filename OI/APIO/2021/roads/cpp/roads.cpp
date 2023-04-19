#include "roads.h"
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct kset
{
    vector<pll> ops;
    multiset<ll, greater<ll>> ms;
    int sz;
    ll sum = 0;
    void resize(int n)
    {
        sz = n;
        while (ms.size() > sz && *ms.begin() >= 0)
        {
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }
    }
    void insert(ll k)
    {
        ops.emplace_back(pll(1, k));
        sum += k;
        ms.insert(k);
        if (ms.size() > sz && *ms.begin() >= 0)
        {
            ops.emplace_back(pll(0, *ms.begin()));
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }
    }
    void undo()
    {
        while (!ops.empty())
        {
            auto [t, k] = ops.back();
            ops.pop_back();
            if (t == 1)
            {
                ms.erase(ms.find(k));
                sum -= k;
            }
            else
            {
                ms.insert(k);
                sum += k;
            }
        }
    }
} opt[100005];
ll dp[100005][2], d[100005], vis[100005];
vector<pll> E[100005];

void dfs(int u, int p, int k)
{
    vis[u] = 1;
    ll tot = dp[u][0] = dp[u][1] = 0;
    opt[u].ops.clear();
    for (auto [v, w] : E[u])
        if (d[v] < k)
            break;
        else if (v != p)
        {
            dfs(v, u, k);
            tot += dp[v][1];
            opt[u].insert(dp[v][0] + w - dp[v][1]);
        }
    dp[u][0] = tot + opt[u].sum - max(*opt[u].ms.begin(), 0LL);
    dp[u][1] = tot + opt[u].sum;
    opt[u].undo();
}

vector<ll> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W)
{
    vector<ll> ans(N);
    vector<int> cur, nxt;
    for (int i = 0; i < N; i++)
        cur.emplace_back(i);
    for (int i = 0; i < N - 1; i++)
    {
        ++d[U[i]], ++d[V[i]];
        E[U[i]].emplace_back(pll(V[i], W[i]));
        E[V[i]].emplace_back(pll(U[i], W[i]));
        ans[0] += W[i];
    }
    for (int i = 0; i < N; i++)
        sort(E[i].begin(), E[i].end(), [&](pll p1, pll p2)
             { return d[p1.F] > d[p2.F]; });

    for (int k = 1; k < N; k++)
    {
        for (auto i : cur)
        {
            vis[i] = 0;
            opt[i].resize(d[i] - k);
        }
        for (auto i : cur)
            if (!vis[i])
            {
                dfs(i, -1, k);
                ans[k] += dp[i][1];
            }
        nxt.clear();
        for (auto i : cur)
            if (d[i] == k)
            {
                for (auto [j, w] : E[i])
                    if (d[j] > d[i])
                        opt[j].insert(w);
            }
            else
                nxt.emplace_back(i);
        cur.swap(nxt);
    }
    return ans;
}

/*
5
0 1 1
0 2 4
0 3 3
2 4 2

4
0 1 5
2 0 10
0 3 5
*/
