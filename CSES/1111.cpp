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

ll n, man[2000006];
string s, t;

signed main()
{
    fast;
    cin >> s;
    n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (i)
            t.push_back('$');
        t.push_back(s[i]);
    }
    int mx = 0;
    for (int i = 0; i < t.size(); i++)
    {
        man[i] = 1;
        man[i] = min(man[mx] + mx - i, man[2 * mx - i]);
        while (man[i] + i < t.size() && i - man[i] >= 0 && t[i + man[i]] == t[i - man[i]])
            man[i]++;
        if (i + man[i] > mx + man[mx])
            mx = i;
    }
    mx = 0;
    for (int i = 0; i < t.size(); i++)
    {
        man[i]--;
        if (man[i] > man[mx])
            mx = i;
    }
    for (int i = mx - man[mx]; i <= mx + man[mx]; i++)
        if (t[i] != '$')
            cout << t[i];
}
