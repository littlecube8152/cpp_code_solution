#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, A, pre[1000006];
vector<int> E[1000006];

int dfs(int u)
{
    vector<int> dp;
    for (auto v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dp.emplace_back(max(1, dfs(v)));
        }
    sort(dp.begin(), dp.end(), greater<>());
    int ans = 0;// dp.size();
    for (int i = 0; i < dp.size(); i++)
        ans = max(ans, dp[i] + i);
    return ans;
}

signed main()
{
    cin >> N >> A;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    cout << dfs(A) << '\n';
}