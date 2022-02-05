/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll q, k, n;

ll solve(ll k, ll n)
{
    if(n == 1)
        return 0;
    ll cnt = n / 2;
    if(k <= cnt)
        return 2 * k - 1;
    else if(n % 2)
    {
        ll ans = solve(k - cnt, n - cnt);
        if(ans == 0)
            return n - 1;
        else
            return (ans - 1) * 2;
    }
    else
        return solve(k - cnt, n - cnt) * 2;
}

signed main()
{
    fast;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> n >> k;
        cout << solve(k, n) + 1 << '\n';
    }
}
