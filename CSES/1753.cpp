/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, m, f[1000006], ans;
string s, t;

signed main()
{
    fast;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    t = ' ' + t;
    f[0] = -1;
    for (int i = 1, j = -1; i <= m; i++)
    {
        while(j >= 0)
            if(t[j + 1] == t[i])
                break;
            else
                j = f[j];
        f[i] = ++j;
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while(j >= 0)
            if(t[j + 1] == s[i])
                break;
            else
                j = f[j];
        if(++j == m)
            ans++, j = f[j];
    }
    cout << ans << '\n';
}
