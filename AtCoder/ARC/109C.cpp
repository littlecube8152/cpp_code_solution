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

ll n, k;
char c[205];

char win(char a, char b)
{
    if (a == 'R')
        return (b == 'P' ? b : a);
    if (a == 'S')
        return (b == 'R' ? b : a);
    return (b == 'S' ? b : a);
}

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= k; i++)
    {
        for (int i = 1; i <= n; i++)
            c[i + n] = c[i];
        for (int i = 1; i <= n; i++)
            c[i] = win(c[i * 2 - 1], c[i * 2]);
    }
    cout << c[1] << '\n';
}
