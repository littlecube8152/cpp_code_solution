/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll N, H, W, dp[3005], fac[200005];
pii p[3005];

int inv(int k)
{
    int ans = 1, p = MOD - 2;
    while (p > 0)
    {
        if (p & 1)
            ans = ans * k % MOD;
        p >>= 1;
        k = k * k % MOD;
    }
    return ans;
}

int cal(int k, int r)
{
    return inv(fac[r] * fac[k] % MOD) * (fac[r + k]) % MOD;
}

signed main()
{
    //fast;
    fac[0] = fac[1] = 1;
    for (int i = 1; i <= 200000; i++)
        fac[i] = fac[i - 1] * i % MOD;

    cin >> H >> W >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;

    p[N + 1] = make_pair(H, W);

    sort(p + 1, p + 2 + N);

    for (int i = 1; i <= N + 1; i++)
        dp[i] = cal(p[i].F - 1, p[i].S - 1);

    for (int i = 1; i <= N + 1; i++)
        for (int j = 1; j < i; j++)
            if (p[i].F - p[j].F >= 0 && p[i].S - p[j].S >= 0)
                dp[i] = ((dp[i] - dp[j] * cal(p[i].F - p[j].F, p[i].S - p[j].S))% MOD + MOD) % MOD;

    cout << dp[N + 1] << '\n';
}
