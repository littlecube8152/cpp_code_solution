#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, x, dp[100005], h[10005], w[10005];

signed main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        for (int j = x - h[i]; j >= 0; j--)
            dp[j + h[i]] = max(dp[j + h[i]], dp[j] + w[i]);
    cout << dp[x] << '\n';
}