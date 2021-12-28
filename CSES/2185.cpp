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

ll n, k, ans, val[(1 << 20)], prime[20];

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> prime[i];
    for (int i = (1 << k) - 1; i >= 1; i--)
    {
        val[i] = 1;
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
            {
                if (n / val[i] < prime[j])
                    val[i] = n + 1;
                else
                    val[i] *= prime[j];
            }
        ans += (__builtin_popcount(i) % 2 == 1 ? 1 : -1) * n / val[i];
    }

    cout << ans << '\n';
}
