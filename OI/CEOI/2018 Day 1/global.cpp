#include <bits/stdc++.h>
#define ll long long
#define plll tuple<ll, ll, ll>
using namespace std;

int n, d, a[200005], b[200005], bit[400005], dp[200005][2];

void modify(int pos, int val)
{
    for (int i = pos; i <= 2 * n; i += (i & -i))
        bit[i] = max(bit[i], val);
}

int query(int pos)
{
    int res = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        res = max(res, bit[i]);
    return res;
}

signed main()
{
    cin >> n >> d;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.emplace_back(a[i]);
        v.emplace_back(a[i] + d);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        b[i] = lower_bound(v.begin(), v.end(), a[i] + d) - v.begin() + 1;
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = query(a[i] - 1) + 1;
        modify(a[i], dp[i][0]);
    }
    for (int i = 1; i <= 2 * n; i++)
        bit[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = query(b[i] - 1) + 1;
        modify(a[i], dp[i][0]);
        modify(b[i], dp[i][1]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max({ans, dp[i][0], dp[i][1]});
    cout << ans << '\n';
}
