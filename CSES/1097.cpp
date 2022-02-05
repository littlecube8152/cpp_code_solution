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

ll n, arr[5005], dp[5005][5005], tot;
bool caldp[5005][5005];

ll DP(int L, int R, ll t)
{
    if (L == R)
        return t * arr[L];
    if (!caldp[L][R])
        caldp[L][R] = 1, dp[L][R] = (t == 1 ? max(DP(L + 1, R, -1) + arr[L], DP(L, R - 1, -1) + arr[R]) : min(DP(L + 1, R, 1) - arr[L], DP(L, R - 1, 1) - arr[R]));
    return dp[L][R];
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }
    cout << (tot + DP(1, n, 1)) / 2 << '\n';
}