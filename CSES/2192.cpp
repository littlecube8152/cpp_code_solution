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

pll operator+(pll p1, pll p2)
{
    return pll(p1.F + p2.F, p1.S + p2.S);
}
pll operator-(pll p1, pll p2)
{
    return pll(p1.F - p2.F, p1.S - p2.S);
}
ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}
ll det(pll p1, pll p2)
{
    return det(p1.F, p1.S, p2.F, p2.S);
}
ll dot(pll a, pll b)
{
    return a.F * b.F + a.S * b.S;
}
ll cross(pll p, pll a, pll b)
{
    return det(a - p, b - p);
}
int ori(pll p, pll a, pll b)
{
    ll d = cross(p, a, b);
    return d < 0 ? -1 : (d == 0 ? 0 : 1);
}
bool intersect(pll p1, pll p2, pll p3, pll p4)
{
    ll s123 = ori(p1, p2, p3), s124 = ori(p1, p2, p4),
       s341 = ori(p3, p4, p1), s342 = ori(p3, p4, p2),
       o123 = dot(p1 - p3, p2 - p3), o124 = dot(p1 - p4, p2 - p4),
       o341 = dot(p3 - p1, p4 - p1), o342 = dot(p3 - p2, p4 - p2);
    if (s123 == 0 && s124 == 0)
        return o123 <= 0 || o124 <= 0 || o341 <= 0 || o342 <= 0;
    return s123 * s124 <= 0 && s341 * s342 <= 0;
}

int n, m;
pll p[1001], q;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        bool on = 0;
        cin >> q.F >> q.S;
        for (int i = 1; i <= n; i++)
        {
            if (intersect(q, q + pll(2e9, 1), p[i], p[i % n + 1]))
                cnt++;
            if (cross(q, p[i], p[i % n + 1]) == 0 && dot(p[i] - q, p[i % n + 1] - q) <= 0)
                on = 1;
        }
        if(on)
            cout << "BOUNDARY\n";
        else
            cout << (cnt & 1 ? "INSIDE\n" : "OUTSIDE\n");
    }
}
