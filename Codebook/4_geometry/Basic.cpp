#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define ll long long
#define F first
#define S second

pll operator+(pll p1, pll p2)
{ return pll(p1.F + p2.F, p1.S + p2.S); }
pll operator-(pll p1, pll p2)
{ return pll(p1.F - p2.F, p1.S - p2.S); }
ll det(ll a, ll b, ll c, ll d)
{ return a * d - b * c; }
ll det(pll p1, pll p2)
{ return det(p1.F, p1.S, p2.F, p2.S); }
ll dot(pll a, pll b)
{ return a.F * b.F + a.S * b.S; }
ll cross(pll p, pll a, pll b)
{ return det(a - p, b - p); }
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
{ return dot(p - q, p - q); }