/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;


signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    if(n > m)
        swap(n, m);
    if(n == 1)
        cout << m << '\n';
    else if(n == 2)
        cout << n * m - n * (m / 4) * 2 - n * (m % 4 >= 2 ? m % 4 - 2 : 0) << '\n';
    else
        cout << (n * m + 1) / 2 << '\n';
}
