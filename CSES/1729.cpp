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

int n, k, dp[1000005];
vector<int> v;

signed main()
{
    fast;

    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int p;
        cin >> p;
        v.emplace_back(p);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j : v)
            if(i - j >= 0)
                dp[i] |= !dp[i - j];
    for (int i = 1; i <= n; i++)
        cout << (dp[i] ? 'W' : 'L');
    cout << '\n';
}