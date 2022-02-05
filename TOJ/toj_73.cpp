/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, p;
vector<double> a;

double cal(double d)
{
    double res = -1;
    for (auto i : a)
        res *= (d - i);
    return res;
}

double bs(double l, double r)
{
    // cout << "TS " << l << " to " << r << " \n";
    if (abs(r - l) < 2e-7)
        return l;
    double onethr = (2.0 * l + r) / 3.0, twothr = (l + 2.0 * r) / 3.0;
    if (cal(onethr) < cal(twothr))
        return bs(onethr, r);
    else
        return bs(l, twothr);
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        a.pb(d);
    }
    cin >> p;
    cout << fixed << setprecision(6) << bs(a[p], a[p + 1]) << '\n';
}
