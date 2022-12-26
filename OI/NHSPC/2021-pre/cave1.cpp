#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, pre[300005], e[300005][20], pos[19], tp[19], tcnt;
vector<int> E[300005];
map<int, bool> dp[(1 << 19)];
map<int, pll> rev[(1 << 19)];
void dfs(int k)
{
    for (int i : E[k])
    {
        dfs(i);
        for (int j = 0; j < tcnt; j++)
            e[k][j] |= e[i][j];
    }
}

signed main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int u;
            cin >> u;
            E[i].emplace_back(u);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        if (a != -1)
        {
            pos[tcnt] = i;
            tp[tcnt] = a;
            e[i][tcnt] = 1;
            tcnt++;
        }
    }
    assert(tcnt <= 18);
    dfs(1);
    //for (int i = 1; i <= N; i++)
     ///   for (int j = 0; j < tcnt; j++)
     //       cout << e[i][j] << " \n"[j == tcnt - 1];
    dp[0][1] = 1;
    for (int mask = 0; mask < (1 << tcnt); mask++)
        for (auto p : dp[mask])
            for (int j = 0; j < tcnt; j++)
                if (e[p.F][j] && (mask & (1 << j)) == 0)
                {
                    dp[mask ^ (1 << j)][tp[j]] = 1;
                    rev[mask ^ (1 << j)][tp[j]] = {mask, p.F};
                }
    if (!dp[(1 << tcnt) - 1].empty())
    {
        int i = dp[(1 << tcnt) - 1].begin()->F, mask = (1 << tcnt) - 1;
        vector<int> ans;
        while (mask > 0)
        {
            ans.emplace_back(mask);
            int newi = rev[mask][i].S, newmask = rev[mask][i].F;
            i = newi, mask = newmask;
        }
        ans.emplace_back(0);
        reverse(ans.begin(), ans.end());
        cout << "Yes\n";
        for (int i = 1; i < ans.size(); i++)
            cout << pos[__lg(ans[i] ^ ans[i - 1])] << " \n"[i == ans.size() - 1];
    }
    else
        cout << "No\n";
}