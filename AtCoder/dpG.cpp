#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> e[100005];
int dp[100005], deg[100005];
int n, m, ans;
queue<int> q;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        deg[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        ans = max(ans, dp[q.front()]);
        for (int i : e[q.front()])
        {
            dp[i] = max(dp[i], dp[q.front()] + 1);
            deg[i]--;
            if(!deg[i])
                q.push(i);
        }
        q.pop();
    }
    cout << ans << '\n';
}