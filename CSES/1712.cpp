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

int n, a, b, c;

ll fast_pow(ll base, ll p, ll mod)
{
    if (p == 0)
        return 1;
    if (p % 2)
        return (base * fast_pow(base, p - 1, mod)) % mod;
    ll half = fast_pow(base, p / 2, mod);
    return (half * half) % mod;
}

signed main()
{
    fast;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        cout << fast_pow(a, fast_pow(b, c, MOD - 1), MOD) << '\n';
    }
}