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
    while (t--)
    {
        int n, x, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            cnt += x & 1;
        }

        // Claim : when all piles are even, this is a losing position 
        // Proof : The second player can do as the first player does.
        // Thus this keeps all piles are even, and the ending position is [], which all piles is even
        // 
        // Therefore, first player wins iff exists a pile its number is odd. 
        if (!cnt)
            cout << "second\n";
        else
            cout << "first\n";
    }
}
