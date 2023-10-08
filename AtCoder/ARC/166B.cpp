#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

ll N, a, b, c, A[200005], dp[200005][8];

signed main()
{
    fast;
    cin >> N >> a >> b >> c;
    for (int i = 0; i <= N; i++)
        for (int m = 1; m < 8; m++)
            dp[i][m] = 2e18;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        for (int m = 0; m < 8; m++)
        {
            ll prod = 1;
            if (m & 1)
                prod = lcm(prod, a);
            if (m & 2)
                prod = lcm(prod, b);
            if (m & 4)
                prod = lcm(prod, c);
            ll cost = (prod + (-A[i] % prod)) % prod;
            for (int p = 0; p < 8; p++)
                dp[i][m | p] = min(dp[i][m | p], dp[i - 1][p] + cost);
        }
    }
    cout << dp[N][7] << '\n';
}