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

ll n, q, pre[200005][25];
vector<int> E[200005];

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
        cin >> pre[i][0];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i <= n; i++)
            pre[i][p] = pre[pre[i][p - 1]][p - 1];
    for (int i = 1; i <= q; i++)
    {
        int k, x;
        cin >> x >> k;
        for (int p = 20; p >= 0; p--)
            if (k >= (1 << p))
            {
                x = pre[x][p];
                k -= (1 << p);
            }
        cout << (x == 0 ? -1 : x) << '\n';
    }
}
