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

ll n, arr[401], dp[401][401];
bool cdp[401][401];

ll DP(int L, int R)
{
    if (L == R)
        return 0;
    if (!cdp[L][R])
    {
        cdp[L][R] = 1, dp[L][R] = 10000000000000;
        for (int i = L; i <= R - 1; i++)
            dp[L][R] = min(dp[L][R], DP(L, i) + DP(i + 1, R) + arr[R] - arr[L - 1]);
        
    }

    return dp[L][R];
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i - 1];
    cout << DP(1, n) << '\n';
}