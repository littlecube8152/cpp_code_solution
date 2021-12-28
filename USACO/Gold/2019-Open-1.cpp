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

ll n, k, m[405][405], dp[405][405], a[405];
signed main()
{
    ifstream cin;
    cin.open("snakes.in");
    ofstream cout;
    cout.open("snakes.out");

    cin >> n >> k;
    k++;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (j == i)
                m[i][j] = a[i];
            else
                m[i][j] = max(m[i][j - 1], a[j]);

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 100000000000;
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= k; j++)
            for (ll p = 1; p <= i; p++)
                dp[i][j] = min(dp[i][j], dp[p - 1][j - 1] + m[p][i] * (i - p + 1) - (a[i] - a[p - 1]));

    cout << dp[n][k] << '\n';
}