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

void solve(int a, int b, int c, int d)
{
    if (a + b - 1 < c + d || abs(c - d) > 1)
        cout << -1 << '\n';
    else if (c == d)
    {
        // 4..474747..74
        // 74..474747..7
        string s = "";
        while (c--)
            s += "47";
        for (auto e : s)
            (e == '4' ? a : b)--;

        if (a < 1 || b < 0)
        {
            if (a < 0 || b < 1)
                cout << -1 << '\n';
            else
            {
                b--;
                cout << '7' << string(a, '4') << s << string(b, '7') << '\n';
            }
        }
        else
        {
            a--;
            cout << string(a, '4') << s << string(b, '7') << '4' << '\n';
        }
    }
    else if (c > d)
    {
        // 4747
        string s = "";
        while (c--)
            s += "47";
        for (auto e : s)
            (e == '4' ? a : b)--;
        if (a < 0 || b < 0)
            cout << -1 << '\n';
        else
            cout << string(a, '4') << s << string(b, '7') << '\n';
    }
    else if (c < d)
    {
        // 74...47...74

        string s;
        while (c--)
            s += "47";
        a--, b--;
        for (auto e : s)
            (e == '4' ? a : b)--;
        if (a < 0 || b < 0)
            cout << -1 << '\n';
        else
            cout << '7' << string(a, '4') << s << string(b, '7') << '4' << '\n';
    }
}

signed main()
{
    fast;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    solve(a, b, c, d);
}
