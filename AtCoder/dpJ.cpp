#pragma GCC optimize("Ofast,unroll-loops")
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

double dp[305][305][305], n;
bool caldp[305][305][305];

double DP(int i, int j, int k)
{
    if (i == 0 && j == 0 && k == 0)
        return 0;
    if (!caldp[i][j][k])
    //Calulate E = pΣ(n+1)(1-p)^n
    //E = pΣ(n+1)(1-p)^n
    //E = pΣn(1-p)^n + pΣ(1-p)^n
    //E = pΣn(1-p)^n + p( 1 / (1-(1-p)) )
    //E = pΣn(1-p)^n + 1
    //E = (1-p)pΣ(n(1-p)^(n-1) + 1
    //E = (1-p)pΣ(n+1)(1-p)^n + 1
    //E = (1-p)E + 1
    //pE = 1
    //E = 1/p
        caldp[i][j][k] = 1, dp[i][j][k] = (double)n / (i + j + k) +
                                          (i > 0 ? DP(i - 1, j, k) * i / (i + j + k) : 0) +
                                          (j > 0 ? DP(i + 1, j - 1, k) * j / (i + j + k) : 0) +
                                          (k > 0 ? DP(i, j + 1, k - 1) * k / (i + j + k) : 0);
    return dp[i][j][k];
}

signed main()
{
    clock_t t = clock();
    cin >> n;
    int b = 0, c = 0, d = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            b++;
        if (x == 2)
            c++;
        if (x == 3)
            d++;
    }
    cout << fixed << setprecision(14) << DP(b, c, d) << '\n';
}