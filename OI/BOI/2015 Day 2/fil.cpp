#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, k, s, dep[6006], occ[2000006], l[6006], ans[6006];
vector<int> E[6006], cur, child[6006];

void dfs(int u)
{
    if (u <= n)
    {
        cur.emplace_back(u);
        for(auto p : cur)
            child[p].emplace_back(u);
        for (auto v : E[u])
        {
            dep[v] = dep[u] + l[v];
            dfs(v);
        }
        cur.pop_back();
    }
    else
    {
        ans[u] = (dep[u] == k);
        for (int i = 1; i * i <= k - dep[u]; i++)
            if ((k - dep[u]) % i == 0)
            {
                int j = (k - dep[u]) / i;
                ans[u] |= (occ[i] || occ[j]);
            }
    }
}

void dfscycle(int u)
{
    if (u <= n)
    {
        for (auto c : child[u])
            occ[dep[c] - dep[u] + s]++;

        for (auto v : E[u])
            dfscycle(v);
        

        for (auto c : child[u])
            occ[dep[c] - dep[u] + s]--;
    }
    else
    {
        ans[u] = (dep[u] == k);
        for (int i = 1; i * i <= k - dep[u]; i++)
            if ((k - dep[u]) % i == 0)
            {
                int j = (k - dep[u]) / i;
                ans[u] |= (occ[i] || occ[j]);
            }
    }
}

void dfsjump(int u)
{
    if (u <= n)
    {
        cur.emplace_back(u);
        for (auto v : E[u])
            dfsjump(v);
        cur.pop_back();
    }
    else
    {
        for (auto p : cur)
        {
            int d = k - (dep[u] - dep[p] + s);
            if(d >= 0)
                ans[u] |= occ[d];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k >> s;
    s++;
    for (int i = 1; i <= n + m; i++)
    {
        int p;
        cin >> p >> l[i];
        l[i]++;
        E[p].emplace_back(i);
    }
    dfs(0);
    dfscycle(0);
    for (int i = 0; i <= n; i++)
        occ[dep[i]]++;
    dfsjump(0);
    for (int i = n + 1; i <= n + m; i++)
        cout << (ans[i] ? "YES\n" : "NO\n");
}