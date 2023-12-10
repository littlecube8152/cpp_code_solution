#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, c, dp[1005], a[205];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c;
    while(cin >> a[n++]);
    n /= 2;
    for (int i = 0; i < n; i++)
    {
        int v = a[i], w = a[i + n];
        for (int i = c; i >= w; i--)
            dp[i] = max(dp[i], dp[i - w] + v);
    }
    cout << dp[c] << '\n';
}