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
        cin >> v[i] >> w[i];
 
    for (int i = 1; i <= n; i++)
        for (int j = c - v[i]; j >= 0; j--)
            dp[j + v[i]] = max(dp[j + v[i]], dp[j] + w[i]);
    cout << dp[c] << '\n';
}