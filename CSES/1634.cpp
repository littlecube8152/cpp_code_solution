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

int n, x, dp[1000005];
vector<int> c;

signed main()
{
    cin >> n >> x;
    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i <= x; i++)
        dp[i] = -1;
    for (int i = 0; i <= x; i++)
        if (dp[i] != -1)
            for (int j : c)
                if (i + j <= x)
                {
                    if (dp[i + j] == -1)
                        dp[i + j] = dp[i] + 1;
                    else
                        dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
    cout << dp[x] << '\n';
}