#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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

ll n, k, a[105], dp[105][8], ans = 1000000000000;
signed main()
{
    fast;
    ifstream cin;
    cin.open("cbarn2.in");
    ofstream cout;
    cout.open("cbarn2.out");

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 1000000000000;

        for (int i = 0; i < n; i++)
            for (int j = 1; j <= k; j++)
            {
                ll res = 0;
                for (ll k = 0; k <= i; k++)
                    res += k * a[(k + p) % n];

                dp[i][j] = min(dp[i][j], res);

                for (ll k = 1; k <= i; k++)
                {
                    res = dp[k - 1][j - 1];
                    for (ll l = k; l <= i; l++)
                    {
                        res += (l - k) * a[(l + p) % n];
                        if(res > dp[i][j])
                            break;
                        if(res > ans)
                            res = 1000000000;
                    }
                    dp[i][j] = min(dp[i][j], res);
                }
            }
        ans = min(ans, dp[n - 1][min(n, k)]);
    }
    cout << ans << '\n';
}