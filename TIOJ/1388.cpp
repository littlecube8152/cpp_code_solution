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

ll n, a[501][501], ans;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i - 1][j];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            ll tmp = 0;
            for (int k = 1; k <= n; k++)
                tmp = max(0LL, tmp + a[j][k] - a[i - 1][k]), ans = max(ans, tmp);
        }
    cout << ans << '\n';
}