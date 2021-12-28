#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define _INFINITY 9223372036854775807
using namespace std;

ll n, a[1005], dp[1005], nC[1005][1005];

ll C(ll m, ll n)
{
    if (m < n || m < 0 || n < 0)
        return 0;
    if (m == n || n == 0)
        return 1;
    if (nC[m][n] == 0)
        nC[m][n] = (C(m - 1, n) + C(m - 1, n - 1)) % MOD;
    return nC[m][n];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i - 1] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = n; j > i; j--)
            if (a[i] > 0)
                dp[j] = (dp[i - 1] * C(j - i, a[i]) + dp[j]) % MOD;
    cout << dp[n];
}