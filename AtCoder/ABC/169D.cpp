/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

ll n, ans;
signed main()
{
    fast;
    cin >> n;
    for (int i = 2; i <= sqrt(n);i++)
    {
        int p = 0;
        while(n % i == 0)
            n /= i, p++;
        if(p > 0)
            ans += (int)(-1+sqrt(1 + 8 * p))/2;
    }
    if(n > 1)
        ans++;
    cout << ans;
}

// nn + n = 2p
// n = (-1+sqrt(1 + 8 * p))/2