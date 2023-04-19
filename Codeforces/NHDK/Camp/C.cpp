/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

map<ll, ll> mp;
ll n, a, b, c, w[500005];
signed main()
{
    fast;
    cin >> n;
    assert(n == 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        w[i] = 2000000000 * (a - b) + (b - c);
        mp[w[i]]++;
    }
    for (int i = 1; i <= n; i++)
        cout << mp[-w[i]] - (w[i] == 0) << " \n"[i == n];
}
