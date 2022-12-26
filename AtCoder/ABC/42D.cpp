/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll inv(ll b)
{
    ll a = 1, p = MOD - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return a;
}

int N, M, A, B;
ll fac[200005], ans;

ll C(int n, int m)
{
    return fac[n] * inv(fac[n - m] * fac[m] % MOD) % MOD;
}

signed main()
{
    fast;
    fac[0] = 1;
    cin >> N >> M >> A >> B;
    for (int i = 1; i <= N + M; i++)
        fac[i] = fac[i - 1] * i % MOD;
    ans = C(N - 1 + M - 1, N - 1);
    if (A > 1)
        for (int i = 1; i <= B; i++)
            ans = (ans - (C(N - A + i - 1, i - 1) * C(A - 2 + M - i, M - i) % MOD) + MOD) % MOD;
    ans = (ans - (C(N - A + B - 1, N - A) * C(A - 1 + M - B - 1, A - 1) % MOD) + MOD) % MOD;
    cout << ans << '\n';
}
