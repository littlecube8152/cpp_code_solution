#include <bits/stdc++.h>
#define ll long long
#define plll tuple<ll, ll, ll>
using namespace std;

ll n, m, dp[100005];
vector<plll> items;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, f, v;
        cin >> c >> f >> v;
        items.emplace_back(make_tuple(f, c, -v));
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int c, f, v;
        cin >> c >> f >> v;
        items.emplace_back(make_tuple(f, -c, v));
    }
    sort(items.begin(), items.end(), greater<>());
    for (int i = 1; i <= n * 50; i++)
        dp[i] = -1e18;
    for (int i = 1; i <= n + m; i++)
    {
        auto [f, c, v] = items[i - 1];
        if (c > 0)
            for (int j = n * 50; j >= c; j--)
                dp[j] = max(dp[j], dp[j - c] + v);
        else
            for (int j = 0; j <= n * 50 + c; j++)
                dp[j] = max(dp[j], dp[j - c] + v);
    }
    ll ans = 0;
    for (int i = 0; i <= n * 50; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}
