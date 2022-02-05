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

ll n, T, f[100005], d[100005], c[100005], ans, v[2][100005];

signed main()
{
    fast;
    while (cin >> T >> n)
    {
        ans = 0;
        for (int i = 1; i <= T; i++)
            v[0][i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> f[i];
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++)
        {
            T -= c[i];
            ll res = 0;
            for (int j = 1, k = 1; j <= T; j++)
            {
                if (v[(i - 1) % 2][k] > f[i])
                    v[i % 2][j] = v[(i - 1) % 2][k++];
                else
                    v[i % 2][j] = f[i], f[i] -= d[i];
                if (v[i % 2][j] < 0)
                    v[i % 2][j] = 0;
                res += v[i % 2][j];
            }
            ans = max(res, ans);
        }
        cout << ans << '\n';
    }
}
