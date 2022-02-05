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

int n, q, arr[200005], bit[400005];

signed main()
{
    //fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    q = n;
    n = (1 << (__lg(n) + 1));
    for (int i = 1; i <= n; i++)
        bit[i] = (((i & -i)));
    for (int i = 1; i <= q; i++)
    {
        int p, pos = n, acc = 0, res = n;
        cin >> p;
        while (1)
        {
            if (bit[pos] + acc == p)
                res = min(res, pos);
            if ((pos & -pos) <= 1)
                break;
            if (bit[pos] + acc >= p)
                pos -= (pos & -pos) / 2;
            else
            {
                acc += bit[pos];
                pos += (pos & -pos) / 2;
            }
        }
        cout << arr[res] << " \n"[i == q];
        for (int j = res; j <= n; j += (j & -j))
            bit[j]--;
    }
}
