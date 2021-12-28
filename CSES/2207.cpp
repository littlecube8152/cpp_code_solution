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

int t, n;

signed main()
{
    fast;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if((n == 1) || (n == 2) || (n == 4) || (n == 7) || (n == 10) || (n == 20) || (n == 23) || (n == 26) || (n == 50) || (n == 53) || (n == 270) || (n == 273) || (n == 276) || (n == 282) || (n == 285) || (n == 288) || (n == 316) || (n == 334) || (n == 337) || (n == 340) || (n == 346) || (n == 359) || (n == 362) || (n == 365) || (n == 386) || (n == 389) || (n == 392) || (n == 566) || (n == 630) || (n == 633) || (n == 636) || (n == 639) || (n == 673) || (n == 676) || (n == 682) || (n == 685) || (n == 923) || (n == 926) || (n == 929) || (n == 932) || (n == 1222))
            cout << "second\n";
        else
            cout << "first\n";
    }
}