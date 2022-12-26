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

ll K;

int S(ll n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

signed main()
{
    fast;
    cin >> K;
    for (int i = 1; i <= 9; i++)
        if (K--)
            cout << i << '\n';
        else
            return 0;
    for (ll i = 10, j = 1; i <= 1e15;)
    {
        for (;; j++)
        {
            ll n = (j + 1) * i - 1, m = (j + 2) * i - 1;
            if (n * S(m) <= m * S(n))
            {
                if (K--)
                {
                    cerr << n / (double)S(n) << " ";
                    cout << j << i - 1 << '\n';
                }
                else
                    return 0;
            }
            else
                break;
        }
        j = (j + 1) / 10;
        i *= 10;
    }
}
