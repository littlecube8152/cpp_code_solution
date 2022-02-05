#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;

ll N, D, dp[100005], pre[100005], subtree[100005], crit[100005], L, K, dpL[100005], Npow[100005];
vector<int> E[100005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            if (dp[i] == 0)
                dp[k]++;
        }
}

ll fastpow(ll b, ll p)
{
    ll a = 1;
    while (p > 0)
    {
        if (p & 1)
            a = a * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return a;
}

void dfs2(int k, bool w)
{
    //cout << "dfs2 " << k << '\n';
    if (w && dp[k] == 1)
        for (int i : E[k])
        {
            if (i != pre[k])
            {
                if (dp[i] == 0)
                {
                    dfs2(i, false);
                    subtree[k] += subtree[i];
                }
                else
                    dfs2(i, true);
            }
        }
    else if (w)
        for (int i : E[k])
        {
            if (i != pre[k])
                dfs2(i, dp[i] != 0);
        }
    else if (!w)
    {
        subtree[k]++;
        for (int i : E[k])
            if (i != pre[k])
            {
                dfs2(i, true);
                subtree[k] += subtree[i];
            }
    }
}

void reroot(int k)
{
    //cout << "reroot " << k << '\n';
    //for (int i = 1; i <= N; i++)
    //    cout << subtree[i] << " \n"[i == N];
    //for (int i = 1; i <= N; i++)
    //    cout << dp[i] << " \n"[i == N];
    int sum = 0;
    if (dp[k] == 0)
        crit[k] = 1;
    for (int i : E[k])
    {
        if (dp[k] == 1 && dp[i] == 0)
            crit[k] += subtree[i];
        else if (dp[k] == 0)
            crit[k] += subtree[i];

        if (dp[k] == 2 && dp[i] == 0)
            sum += subtree[i];
        else if (dp[k] == 1 && dp[i] == 1)
            sum += subtree[i];
    }
    swap(subtree[k], crit[k]);
    for (int i : E[k])
        if (i != pre[k])
        {
            if (dp[k] == 1 && dp[i] == 0)
            {
                ll tmp = sum + 1;
                swap(tmp, subtree[k]);
                dp[k]--, dp[i]++;
                reroot(i);
                dp[k]++;
                swap(tmp, subtree[k]);
            }
            else if (dp[k] >= 2 && dp[i] == 0)
            {
                ll tmp = (dp[k] == 2 ? sum - subtree[i] : 0);
                swap(tmp, subtree[k]);
                dp[k]--;
                reroot(i);
                dp[k]++;
                swap(tmp, subtree[k]);
            }
            else if (dp[k] == 0)
            {
                ll tmp = subtree[k] - subtree[i];
                swap(tmp, subtree[k]);
                dp[i]++;
                reroot(i);
                swap(tmp, subtree[k]);
            }
            else
                reroot(i);
        }
    swap(subtree[k], crit[k]);
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

    dfs(1);
    dfs2(1, dp[1] != 0);
    reroot(1);
    //for (int i = 1; i <= N; i++)
    //    cout << crit[i] << " \n"[i == N];
    //for (int i = 1; i <= N; i++)
    //    cout << dp[i] << " \n"[i == N];
    for (int i = 1; i <= N; i++)
        if (dp[i] == 0)
            L++, K = (K - crit[i] + MOD) % MOD;
        else
            K = (K + crit[i] + MOD) % MOD;
    ll res = L * (((fastpow(N, D * 2) - fastpow(K, D) + MOD) % MOD) * fastpow((N * N - K + MOD) % MOD, MOD - 2) % MOD) % MOD;
    if (dp[1] == 0)
        cout << (res * crit[1]) % MOD << '\n';
    else
        cout << (fastpow(N, D * 2) - (res * crit[1] % MOD) + MOD) % MOD << '\n';
}
/*
7 1
1 2
2 3
3 4
4 5
5 6
6 7
*/
