#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define double long double
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

pdd operator+(pdd p, pdd q)
{
    return pdd(p.F + q.F, p.S + q.S);
}

pdd operator-(pdd p, pdd q)
{
    return pdd(p.F - q.F, p.S - q.S);
}

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

double det(pdd p, pdd q)
{
    return det(p.F, p.S, q.F, q.S);
}

double dot(pdd p, pdd q)
{
    return p.F * q.F + p.S * q.S;
}

double cross(pdd p, pdd a, pdd b)
{
    return det(a - p, b - p);
}

const double eps = 1e-18;

int ori(pdd p, pdd a, pdd b)
{
    double d = cross(p, a, b);
    return abs(d) < eps ? 0 : (d < 0 ? -1 : 1);
}

bool btw(pdd p, pdd a, pdd b)
{
    return ori(p, a, b) == 0 && dot(a - p, b - p) <= eps;
}

double dis2(pdd a, pdd b)
{
    return dot(a - b, a - b);
}

vector<pdd> convex(vector<pdd> v)
{
    vector<pdd> h;
    sort(v.begin(), v.end());
    for (int t = 0; t < 2; t++)
    {
        for (pdd p : v)
        {
            while (h.size() >= 2 && (ori(h.back(), h[h.size() - 2], p) < 0 || btw(h.back(), h[h.size() - 2], p)))
                h.pop_back();
            h.emplace_back(p);
        }
        reverse(v.begin(), v.end());
    }
    h.pop_back();
    return h;
}

const int c = 16000;
const double pi = acosl(-1);
double x[c + 5], y[c + 5], a[c + 5];
int r[505];

signed main()
{
    for (int i = 0; i < c; i++)
        a[i] = 2.0 * pi / (double)(c) * (double)(i),
        x[i] = cosl(a[i]),
        y[i] = sinl(a[i]);

    int n;
    cin >> n;
    vector<pdd> v;
    for (int i = 1; i <= n; i++)
    {
        int x0, y0;
        cin >> x0 >> y0 >> r[i];
        r[i] += 10;
        for (int j = 0; j < c; j++)
        {
            pdd p = pdd(x0 + r[i] * x[j], y0 + r[i] * y[j]);
            v.emplace_back(p);
        }
    }
    v = convex(v);
    n = (int)v.size();
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += sqrtl(dis2(v[i], v[(i + 1) % n]));

    cout << fixed << setprecision(20) << ans << '\n';
}