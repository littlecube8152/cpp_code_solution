/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int inv(int k)
{
    if(k == 1)
        return k;
    return (MOD - (MOD / k)) * inv(MOD % k) % MOD;
}

int n, cnt[1005], dp[1005][1005], invf[1005];
signed main()
{
    fast;
    cin >> n;
    invf[1] = 1;
    for (int i = 2; i <= 1000; i++)
        invf[i] = invf[i - 1] * inv(i) % MOD;
    for (int i = 1; i <= n; i++)
        cin >> cnt[i];
    for (int i = n; i > 0; i--)
        cnt[i] += cnt[i + 1];
    dp[1][n] = cnt[n];
    for (int i = 2; i <= cnt[1]; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i - 1][j] * max(0LL, cnt[j] - (i - 1)) + dp[i - 1][j + 1] * (cnt[j] - cnt[j + 1])) % MOD;

    for (int i = 1; i <= n;i++)
        dp[cnt[1]][1] = dp[cnt[1]][1] * invf[cnt[i] - cnt[i + 1]] % MOD;
    cout << dp[cnt[1]][1];
}
