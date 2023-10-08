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
    ll n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    s.resize(unique(s.begin(), s.end()) - s.begin());
    if(!s.empty() && s.front() == '1')
        s.erase(s.begin());
    if(!s.empty() && s.back() == '1')
        s.pop_back();
    n = ((int)s.size() + 1) / 2;
    cout << min(max(0LL, (n - 1)) * x + y, n * y) << '\n';
}
