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

int n, dp[1000005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = 1000000;

    for (int i = 1; i <= n; i++)
        for (int j = i; j > 0; j /= 10)
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
    cout << dp[n];
}