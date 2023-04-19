#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

const double eps = 1e-10;
pdd operator+(pdd p, pdd q)
{
    return pdd(p.F + q.F, p.S + q.S);
}
pdd operator-(pdd p, pdd q)
{
    return pdd(p.F - q.F, p.S - q.S);
}
pdd operator*(pdd p, double d)
{
    return pdd(p.F * d, p.S * d);
}
pdd operator/(pdd p, double d)
{
    return pdd(p.F / d, p.S / d);
}
double cross(pdd p1, pdd p2)
{
    return p1.F * p2.S - p1.S * p2.F;
}
double dot(pdd p1, pdd p2)
{
    return p1.F * p2.F + p1.S * p2.S;
}
double cross(pdd p, pdd q1, pdd q2)
{
    return cross(q1 - p, q2 - p);
}
pdd intersect(pdd p1, pdd p2, pdd p3, pdd p4)
{
    double a123 = cross(p1, p2, p3),
           a124 = -cross(p1, p2, p4);
    return (p4 * a123 + p3 * a124) / (a123 + a124);
}
int ori(pdd p, pdd q1, pdd q2)
{
    double c = cross(p, q1, q2);
    return (c > eps ? 1 : (c < eps ? -1 : 0));
}

int N;
pdd p[100005], u, v;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dir = 0;
    cin >> N >> u.F >> u.S >> v.F >> v.S;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].F >> p[i].S;
        int plane = (ori(u, v, p[i]) < 0 ? 1 : 2);
        dir |= plane;
    }
    if (dir == 3)
    {
        cout << -1 << '\n';
        return 0;
    }
    vector<pdd> hull, seq;
    sort(p + 1, p + 1 + N);
    for (int t = 1; t <= 2; t++)
    {
        for (int i = 1; i <= N; i++)
        {
            while (hull.size() >= 2 && (ori(p[i], hull[hull.size() - 1], hull[hull.size() - 2]) < 0 ||
                                        (ori(p[i], hull[hull.size() - 1], hull[hull.size() - 2]) == 0 && dot(p[i] - hull[hull.size() - 1], hull[hull.size() - 2] - hull[hull.size() - 1]) >= 0)))
                hull.pop_back();
            hull.emplace_back(p[i]);
        }
        reverse(p + 1, p + 1 + N);
    }
    hull.pop_back();
    int s = 0, t = -1, cnt = 0;
    for (int i = 0; i < hull.size(); i++)
        if (abs(cross(u, v, hull[i])) >= abs(cross(u, v, hull[s])) + eps)
            s = i, t = -1, cnt = 1;
        else if (abs(cross(u, v, hull[i])) >= abs(cross(u, v, hull[s])) - eps)
            t = i, cnt++;
    assert(cnt <= 2);
    if (s == 0 && t == hull.size() - 1)
        seq = hull;
    else
    {
        for (int i = max(s, t); i < hull.size(); i++)
            seq.emplace_back(hull[i]);
        for (int i = 0; i < max(s, t); i++)
            seq.emplace_back(hull[i]);
    }
    int l = 1, r = 0;
    pdd cur = intersect(p[l - 1], p[l], u, v);
    int N = seq.size();
    for (int i = 1)
}