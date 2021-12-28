//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, fib[505][505], ans;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            fib[i][j] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            for (int l = 1; l <= min(j - i, i); l++)
                fib[i][j] = (fib[i][j] + fib[l][j - i]) % MOD2;
            for (int l = max(i, j - i + 1); l <= (j - 1); l++)
                fib[i][j] = (fib[i][j] + fib[i][l]) % MOD2;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i * j < k)
                ans = (ans + fib[i][n] * fib[j][n]) % MOD2;
    cout << ans * 2 % MOD2;
}