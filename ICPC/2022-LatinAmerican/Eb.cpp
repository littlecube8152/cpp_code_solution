#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, k, e, ans = 1e9;
bitset<1005> dp[1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> e;
    int l = e, r = n - k - e;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (i != k)
        {
            for (int j = r; j >= 0; j--)
            {
                dp[j] |= (dp[j] << i);
                if (j >= i)
                    dp[j] |= dp[j - i];
            }
        }
    for (int i = 0; i <= l; i++)
        for (int j = 0; j <= r; j++)
            if (dp[j][i])
                ans = min(ans, n - k - j - i);
    cout << ans << '\n';
}