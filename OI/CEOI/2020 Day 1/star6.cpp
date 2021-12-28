#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;

ll N, D, state[1005][2], pre[1005], dp[1005][20];
vector<int> E[1005], tr[1005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            if (state[i][0] == 0 && state[k][0] == 0)
                state[k][0] = i;
            else if (state[i][0] == 0)
                state[k][1] = i;
        }
}

void reroot(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            if ((state[k][0] == 0) || (state[k][0] == i && state[k][1] == 0))
            {
                if (state[i][0] == 0)
                    state[i][0] = k;
                else
                    state[i][1] = k;
            }
            reroot(i);
        }
}

void dfs2(int k, bool first, int r)
{
    if (first)
        if (state[k][1] != 0)
            return;
        else
            dfs2(state[k][0], false, r);
    else
    {
        int ans = 1;
        for (int i : E[k])
            if (i != pre[k])
                dfs2(i, true, r);
        tr[r].emplace_back(k);
    }
}

void solve(int r)
{
    for (int i = 1; i <= N; i++)
        state[i][0] = state[i][1] = pre[i] = 0;
    dfs(r);
    dfs2(r, state[r][0] != 0, r);
    reroot(r);
    ll lose = 0;
    for (int i = 1; i <= N; i++)
        if (state[i][0] == 0)
            lose++;
    if (state[r][0])
        dp[r][0] = (N * N - tr[r].size() * lose) % MOD;
    else
        dp[r][0] = (tr[r].size() * lose) % MOD;
}

signed main()
{
    cin >> N >> D;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }

    for (int i = 1; i <= N; i++)
        solve(i);

    for (int i = 1; i <= N; i++)
        cout << tr[i].size() << " \n"[i == N];
    /*
    ll base = N * N % MOD;
    base = (base * base) % MOD;
    for (int p = 1; p < 20; p++, base = (base * base) % MOD)
        for (int i = 1; i <= N; i++)
            if (state[i][0])
                for (int j : tr[i])*/
}
/*

*/