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
    ll t, n, m, a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a = b = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            a += k;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> k;
            b += k;
        }
        if(a < b)
            cout << "Tenzing\n";
        else if(a > b)
            cout << "Tsondu\n";
        else
            cout << "Draw\n";
    }
}
