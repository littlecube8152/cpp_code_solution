#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>
using namespace std;

const ll mod = 998244353;
ll n, a[405], b[405], dp[405][405], c[405][405];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++)
        c[i][i] = c[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        a[p]++;
    }
    dp[0][0] = 1;
    for (int i = n; i >= 1; i--)
        b[i] = b[i + 1] + a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - b[i + 1]; j++)
            for (int k = a[i + 1]; k + j <= n; k++)
                if (j + k >= i + 1)
                {
                    dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * c[n - j - b[i + 1]][k - a[i + 1]]) % mod;
                }
    }
    cout << dp[n][n] << '\n';
}