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

ll n, c, w[100005], v[100005], dp[100005], ans;

signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    dp[0] = c;
    for (int j = 1; j <= 100000; j++)
        dp[j] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 100000 - v[i]; j >= 0; j--)
            if (dp[j] >= w[i])
                dp[j + v[i]] = max(dp[j + v[i]], dp[j] - w[i]);
    }
    for (int j = 0; j <= 100000; j++)
        if (dp[j] >= 0)
            ans = j;
    cout << ans << '\n';
}