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
ll dis2(pll p, pll q)
{
    return dot(p - q, p - q);
}

int quad(pll p)
{
    if (p.F > 0 && p.S >= 0)
        return 1;
    if (p.F <= 0 && p.S > 0)
        return 2;
    if (p.F < 0 && p.S <= 0)
        return 3;
    if (p.F >= 0 && p.S < 0)
        return 4;
    return 0;
}

pll s, e, e2;
ll n, bit[100005];
ll ans;
pll p[100005];
vector<pll> u, d, l, r;

auto angle_sort = [](pll p1, pll p2)
{
    int q1 = quad(p1), q2 = quad(p2);
    if (q1 != q2)
        return q1 < q2;
    return p1.S * p2.F < p2.S * p1.F; };

void modify(int pos, int val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += val;
}

ll query(ll pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

template<typename T>
vector<T> rot(vector<T> v, T target)
{
    vector<T> ans;
    bool in = 0;
    for(auto i : v)
    {
        if(in)
            ans.emplace_back(i);
        if(i == target)
            in = 1;
    }
    for(auto i : v)
    {
        if(i == target)
            in = 0;
        if(in)
            ans.emplace_back(i);
    }
    return ans;
}

void solve(vector<pll> v, bool rev)
{
    ll m = v.size();
    v.emplace_back(e2);
    sort(v.begin(), v.end(), [&](pll p1, pll p2)
          { return dis2(p1, s) < dis2(p2, s); });
    if(rev)
        reverse(v.begin(), v.end());
    stable_sort(v.begin(), v.end(), [&](pll p1, pll p2)
                { return angle_sort(p1 - s, p2 - s); });
    v = rot(v, e2);

    vector<pair<pll, ll>> u;
    for (int i = 0; i < m; i++)
        u.emplace_back(make_pair(v[i], m - i));
    u.emplace_back(make_pair(e2, 0));
    sort(u.begin(), u.end(), [&](pair<pll, ll> p1, pair<pll, ll> p2)
         { return dis2(p1.F, e) > dis2(p2.F, e); });
    if(rev)
        reverse(u.begin(), u.end());
    stable_sort(u.begin(), u.end(), [&](pair<pll, ll> p1, pair<pll, ll> p2)
                { return angle_sort(p1.F - e, p2.F - e); });
    u = rot(u, pair<pll, ll>(e2, 0));

    for (int i = 1; i <= n; i++)
        bit[i] = 0;

    for (auto [p, idx] : u)
    {
        ans += query(idx);
        modify(idx, 1);
    }
}

signed main()
{
    fast;
    cin >> s.F >> s.S >> e.F >> e.S;
    e2 = e + e - s;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= n; i++)
    {
        ll o = ori(s, e, p[i]);
        if (o > 0)
            u.emplace_back(p[i]);
        else if (o < 0)
            d.emplace_back(p[i]);
        else
        {
            if (dot(e - s, p[i] - s) < 0)
                l.emplace_back(p[i]);
            else
                r.emplace_back(p[i]);
        }
    }

    solve(u, 0);
    solve(d, 1);
    ans += l.size() * ((ll)l.size() - 1) / 2;
    ans += r.size() * ((ll)r.size() - 1) / 2;
    cout << ans << '\n';
}
