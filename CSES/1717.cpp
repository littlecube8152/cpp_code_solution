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

ll n, ans[1000005];

signed main()
{
    fast;
    cin >> n;
    ans[1] = 0, ans[2] = 1, ans[3] = 2;
    for (int i = 4; i <= n; i++)
        ans[i] = (i - 1) * (ans[i - 1] + ans[i - 2]) % MOD;
        // consider the new element n is placed at position k(k != n)
        // (i) k is at position n, this case has D_{n - 2} possibility
        // (ii) k is not at position n, swap them, which has D_{n - 1} possibility
    cout << ans[n] << '\n';
}
