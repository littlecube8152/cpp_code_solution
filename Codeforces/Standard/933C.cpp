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
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const double eps = 1e-9;

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
    return pdd(d * p.F, d * p.S);
}

// circle with radius r intersects line ax + by + c = 0
vector<pdd> circIntersectLine(double x, double y, double r, double a, double b, double c)
{
    double f = (a * x + b * y + c), n = a * a + b * b;
    pdd p(x - f / n * a, y - f / n * b);
    double d = r * r - f * f / n;
    if (abs(d) < eps)
        return {p};
    else if (d < 0)
        return {};
    else
    {
        double t = sqrt(d / n);
        return {p - pdd(-b, a) * t, p + pdd(-b, a) * t};
    }
}

vector<pdd> circIntersectCirc(double x0, double y0, double r0, double x1, double y1, double r1)
{
    return circIntersectLine(x0, y0, r0, 2 * (x1 - x0), 2 * (y1 - y0), x0 * x0 - x1 * x1 + y0 * y0 - y1 * y1 - r0 * r0 + r1 * r1);
}

vector<pdd> epsUnique(vector<pdd> v)
{
    if(v.size() <= 1)
        return v;
    int mid = v.size() / 2;
    vector<pdd> l(v.begin(), v.begin() + mid), r(v.begin() + mid, v.end());
    l = epsUnique(l), r = epsUnique(r);
    double x = max_element(all(l))->F;
    vector<pdd> out, in;
    for (auto p : l)
        if(abs(p.F - x) < eps / 2)
            in.emplace_back(p);
        else
            out.emplace_back(p);
    for (auto p : r)
        if(abs(p.F - x) < eps / 2)
            in.emplace_back(p);
        else
            out.emplace_back(p);
    sort(in.begin(), in.end(), [&](pdd p, pdd q)
         { return p.S < q.S; });
    for (int i = 0; i < in.size(); i++)
        if(i && in[i].S - in[i - 1].S < eps)
            continue;
        else
            out.emplace_back(in[i]);
    return out;
}

int n, x[3], y[3], r[3];
vector<pdd> v;

signed main()
{
    cin >> n;
    int cc = n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            auto u = circIntersectCirc(x[i], y[i], r[i], x[j], y[j], r[j]);
            if (!u.empty())
                cc = max(1, cc - 1);
            for (auto p : u)
                v.emplace_back(p);
        }
    sort(v.begin(), v.end());
    v = epsUnique(v);
    int E = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (auto p : v)
            if (abs((p.F - x[i]) * (p.F - x[i]) + (p.S - y[i]) * (p.S - y[i]) - r[i] * r[i]) < eps)
                cnt++;
                
        E += cnt;
    }
    // V - E + F = cc + 1
    cout << cc - v.size() + E + 1 << '\n';
}