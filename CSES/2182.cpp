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

ll n, a = 1, b = 1, c = 1, mul = 1;
pll px[100005];

ll fast_pow(ll base, ll p)
{
    if (p == 0)
        return 1;
    if (p % 2)
        return (base * fast_pow(base, p - 1)) % MOD;
    ll half = fast_pow(base, p / 2);
    return (half * half) % MOD;
}

ll inv(int n)
{
    if (n == 1)
        return 1;
    return (MOD - (MOD / n)) * inv(MOD % n) % MOD;
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> px[i].F >> px[i].S;
        mul = (mul * (px[i].S + 1)) % (MOD - 1);
    }
    for (int i = 1; i <= n; i++)
    {
        a = (a * (px[i].S + 1)) % MOD;
        b = (((b * (fast_pow(px[i].F, px[i].S + 1) - 1)) % MOD) * inv(px[i].F - 1)) % MOD;
        c = (c * fast_pow(px[i].F, (px[i].S * mul) / 2)) % MOD;
    //
    }
    cout << a << " " << b << " " << c << '\n';
}