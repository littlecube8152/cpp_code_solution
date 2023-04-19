#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, deg[100005], invalid = 0, vis[100005];
char ans[100005];
pii oE[100005];
vector<pii> E[100005];

void dfs_chain(int k)
{
    for (auto [i, id] : E[k])
    {
        if (deg[i] > 0)
        {
            deg[i]--;
            deg[k]--;
            if (pii{k, i} == oE[id])
                ans[id] = '>';
            else
                ans[id] = '<';
        }
        if (deg[i] == 1)
            dfs_chain(i);
    }
}

void dfs_cycle(int k)
{
    for (auto [i, id] : E[k])
    {
        if (ans[id] == 0)
        {
            if (pii{k, i} == oE[id])
                ans[id] = '>';
            else
                ans[id] = '<';
            dfs_cycle(i);
        }
    }
}

void solve()
{
    invalid = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int u, v;
        cin >> u >> v;
        oE[i].F = u;
        oE[i].S = v;
        E[u].emplace_back(pii{v, i});
        E[v].emplace_back(pii{u, i});
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= N; i++)
        if (deg[i] == 0)
            invalid = 1;
    for (int i = 1; i <= N; i++)
        if (deg[i] == 1)
        {
            //cout << i << " ";
            dfs_chain(i);
            //for (int i = 1; i <= N; i++)
            //    cout << (ans[i] == 0 ? '_' : ans[i]);
            //cout << '\n';
        }
    //for (int i = 1; i <= N; i++)
    //    cout << deg[i] << " \n"[i == N];
    for (int i = 1; i <= N; i++)
        if (deg[i] != 0 && deg[i] != 2)
            invalid = 2;
    for (int i = 1; i <= N; i++)
        if (ans[i] == 0)
        {
            ans[i] = '<';
            deg[oE[i].F]--;
            deg[oE[i].S]--;
            dfs_cycle(oE[i].F);
        }
    if (invalid)
    {
        cerr << invalid << " ";
        cout << "Impossible\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
            cout << ans[i];
        cout << '\n';
    }
    for (int i = 1; i <= N; i++)
    {
        oE[i] = {0, 0};
        E[i].clear();
        ans[i] = 0;
        deg[i] = 0;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}