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

inline pll findmax(ll k)
{
    ll m = 0, mi = 0;
    for (ll i = 1; i <= 100000000000000000; i *= 10)
    {
        ll num = (k % (i * 10)) / i;
        if (num >= m)
            m = num, mi = i;
    }
    ll num = k / 1000000000000000000;
    if (num >= m)
        m = num, mi = 100000000000000000;
    return pll{m, mi};
}

void solve()
{
}

signed main()
{

    for (int i = 0; i < 2000; i++)
    {
        cout << findmax(i).F << " \n"[i % 10 == 9];
        //dp[i] = dp[i - findmax(i).F] + 1;
        if(i % 100 == 99)
            cout << '\n';
    }
}
