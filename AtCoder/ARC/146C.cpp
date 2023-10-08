/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll mod = MOD2;
ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

int n;

signed main()
{
    fast;
    cin >> n;
    ll ans = 1 + fpow(2, n), cur = fpow(2, n);
    for (int i = 2; i <= n + 1; i++)
    {
        cur = cur * (fpow(2, n) - fpow(2, i - 2)) % mod;
        cur = cur * fpow(i, mod - 2) % mod;
        ans = (ans + cur + mod) % mod;
    }
    cout << ans << '\n';
}
