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

ll n;
string s;

signed main()
{
    fast;
    cin >> s;
    n = s.size();
    s = s + s;
    int i = 0, ans = 0;
    while (i < n)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < s.size() && s[j] >= s[k])
        {
            k = (s[j] > s[k] ? i : k + 1);
            ++j;
        }
        while (i <= k)
            i += j - k;
    }
    for (int i = 0; i < n; i++)
        cout << s[ans + i];
    cout << '\n';
}
