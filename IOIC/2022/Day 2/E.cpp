#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, dp[100005], c[100005], deg[100005];
vector<int> E[100005];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u == v)
            continue;
        E[v].emplace_back(u);
        deg[u]++;
        
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (deg[i] == 0)
            q.push(i);
    for (int i = 1; i <= N; i++)
    {
        int u = q.front();
        q.pop();
        for (int v : E[u])
        {
            --deg[v];
            if (deg[v] == 0)
                q.push(v);
            dp[v] = max({dp[u], dp[v], c[u]});
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += dp[i];
    }
    cout << ans << '\n';
}