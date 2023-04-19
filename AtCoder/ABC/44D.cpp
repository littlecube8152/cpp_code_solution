/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, s;

ll f(ll n, ll b)
{
    return (n < b ? n : f(n / b, b) + n % b);
}

signed main()
{
    fast;
    cin >> n >> s;
    if (n == s)
        cout << n + 1 << '\n';
    else
    {
        ll i = 2;
        for (; i * i <= n; i++)
            if (f(n, i) == s)
            {
                cout << i << '\n';
                return 0;
            }
        i--;
        ll ans = 1e14;
        for (int j = 1;; j++)
        {
            ll l = (n / (j + 1)), r = (n / j), val, a = r;
            if (r <= i)
                break;
            val = f(n, r);
            if ((s - val) % j || s < val)
                continue;
            a -= (s - val) / j;
            if (l < a)
                ans = min(ans, a);
        }
        cout << (ans >= 1e14 ? -1 : ans) << '\n';
    }
}
