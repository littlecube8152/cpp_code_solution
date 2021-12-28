#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;

ll N, D, dp[100005][2], pre[100005];
vector<int> E[100005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            if (dp[i][0] == 0 && dp[k][0] == 0)
                dp[k][0] = i;
            else if (dp[i][0] == 0)
                dp[k][1] = i;
        }
}

void reroot(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            if ((dp[k][0] == 0) || (dp[k][0] == i && dp[k][1] == 0))
            {
                if (dp[i][0] == 0)
                    dp[i][0] = k;
                else
                    dp[i][1] = k;
            }
            reroot(i);
        }
}

ll dfs2(int k, bool first)
{
    if (first)
        if (dp[k][1] != 0)
            return 0;
        else
            return dfs2(dp[k][0], false);
    else
    {
        int ans = 1;
        for (int i : E[k])
            if (i != pre[k])
                ans += dfs2(i, true);
        return ans;
    }
}

signed main()
{
    cin >> N >> D;
    assert(D == 1);
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }

    dfs(1);
    ll cnt = dfs2(1, dp[1][0] != 0);
    reroot(1);
    ll lose = 0;
    for (int i = 1; i <= N; i++)
        if (dp[i][0] == 0)
        {
            lose++;
            //cerr << i << '\n';
        }
    if (dp[1][0])
        cout << (N * N - cnt * lose) % MOD << '\n';
    else
        cout << (cnt * lose) % MOD << '\n';
}