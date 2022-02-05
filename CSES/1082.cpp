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
//#define int long long
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

ll n, ans;

ll bs(ll l, ll r, ll k)
{
    if (l == r)
        return l;
    ll mid = (l + r) / 2;
    if (n / mid > k)
        return bs(mid + 1, r, k);
    else
        return bs(l, mid, k);
}

signed main()
{
    //fast;
    cin >> n;
    ll r = n, k = 1;

    while (r > 1000000)
    {
        ll l = bs(1, r, k);
        ans = (ans + (((((r % MOD) * ((r + 1LL) % MOD)) - ((l % MOD) * ((l - 1) % MOD)) + MOD) % MOD )  * 500000004 % MOD) * k % MOD) % MOD;
        k++;
        r = l - 1;
        //cout << "L = " << l << " k = " << k << '\n';
    }
    for (int i = 1; i <= r; i++)
        ans = (ans + (n / i) * i) % MOD;
    cout << ans << '\n';
}
