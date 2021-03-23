//#pragma GCC optimize("Ofast,unroll-loops")
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

ll n, pre[100005], dp[2][100005];
vector<int> e[100005];

void dfs(int n)
{
    dp[0][n] = 1, dp[1][n] = 1;
    for (int i : e[n])
        if (pre[n] != i)
        {
            pre[i] = n;
            dfs(i);
            dp[1][n] = (dp[1][n] * dp[0][i]) % MOD;
            dp[0][n] = (dp[0][n] * (dp[0][i] + dp[1][i])) % MOD;
        }
}

signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1);
    cout << (dp[0][1] + dp[1][1]) % MOD << '\n';
}