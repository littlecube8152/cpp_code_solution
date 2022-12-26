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

ll n, Z[1000006], ans;
string s;

signed main()
{
    fast;
    cin >> s;
    for (int i = 1, mx = 0; i < s.size(); i++)
    {
        if (i < Z[mx] + mx)
            Z[i] = min(Z[mx] - i + mx, Z[i - mx]);
        while (Z[i] + i < s.size() && s[i + Z[i]] == s[Z[i]])
            Z[i]++;
        if (Z[i] + i > Z[mx] + mx)
            mx = i;
    }
    for (int i = s.size() - 1; i >= 0; i--)
        if (Z[i] + i == s.size())
            cout << Z[i] << ' ';
}
