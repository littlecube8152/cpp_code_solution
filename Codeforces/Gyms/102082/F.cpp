#include <bits/stdc++.h>
using namespace std;
#define double long double
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

pdd operator+(pdd p1, pdd p2)
{
    return pdd(p1.F + p2.F, p1.S + p2.S);
}
pdd operator-(pdd p1, pdd p2)
{
    return pdd(p1.F - p2.F, p1.S - p2.S);
}
pdd operator*(pdd p, double d)
{
    return pdd(p.F * d, p.S * d);
}
pdd operator/(pdd p, double d)
{
    return pdd(p.F / d, p.S / d);
}
double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}
double det(pdd p1, pdd p2)
{
    return det(p1.F, p1.S, p2.F, p2.S);
}
double dot(pdd a, pdd b)
{
    return a.F * b.F + a.S * b.S;
}
double cross(pdd p, pdd a, pdd b)
{
    return det(a - p, b - p);
}

pdd intersection(pdd p1, pdd p2, pdd p3, pdd p4)
{
    double a123 = cross(p1, p2, p3),
           a124 = -cross(p1, p2, p4);
    return (p4 * a123 + p3 * a124) / (a123 + a124);
}
double dis2(pdd p, pdd q)
{
    return dot(p - q, p - q);
}

// when t <= 0.5, return value is nearer to l than to r
pdd interpolate(pdd l, pdd r, double t)
{
    return l * (1.0 - t) + r * t;
}

double btw(double l, double r, double m)
{
    return (l <= m && m <= r) || (r <= m && m <= l);
}

int n;
vector<pdd> p, q;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    p.resize(n);
    for (auto &[x, y] : p)
        cin >> x >> y;

    double A = 0, cur = 0;
    for (int i = 0; i < n; i++)
        A += cross(pdd(0, 0), p[i], p[(i + 1) % n]);
    {
        int j = 0;
        while (cur + cross(p[0], p[j], p[(j + 1) % n]) < A / 2.0)
        {
            cur += cross(p[0], p[j], p[(j + 1) % n]);
            j = (j + 1) % n;
        }
        for (int i = 0; i < n; i++)
        {
            while (cur + cross(p[i], p[j], p[(j + 1) % n]) < A / 2.0)
            {
                cur += cross(p[i], p[j], p[(j + 1) % n]);
                j = (j + 1) % n;
                q.emplace_back(p[j]);
            }
            double diff = A / 2.0 - cur;
            q.emplace_back(interpolate(p[j], p[(j + 1) % n], diff / cross(p[i], p[j], p[(j + 1) % n])));
            cur -= cross(p[j], p[i], p[(i + 1) % n]);
        }
        while (q.size() < 2 * n)
        {
            j = (j + 1) % n;
            q.emplace_back(p[j]);
        }
    }
    double m = 1e18, M = 0;
    for (int A = 0; A < 2 * n; A++)
    {
        // cerr << A << ' ' << q[A].F << ' ' << q[A].S << '\n';
        int B = (A + 1) % (2 * n), C = (A + n) % (2 * n), D = (C + 1) % (2 * n);

        double d = sqrtl(dis2(q[A], q[C]));
        if (abs(det(q[A] - q[B], q[C] - q[D])) > 1e-9)
        {
            pdd x = intersection(q[A], q[B], q[C], q[D]);
            // cerr << x.F << ' ' << x.S << '\n';
            double l = sqrtl(dis2(q[A], x) * dis2(q[C], x));
            // cerr << sqrtl(l) << ' ';
            if (btw(dis2(q[A], x), dis2(q[B], x), l))
            {
                // cerr << "interpolate " << sqrt(dis2(q[A], q[C]) - dis2(q[A], x) - dis2(q[C], x) + l + l) << " !\n";
                m = min(m, sqrt(dis2(q[A], q[C]) - dis2(q[A], x) - dis2(q[C], x) + l + l));
            }
        }
        else
        {
            // cerr << "parallel?\n";
            m = min(m, cross(q[A], q[C], q[D]) / sqrt(dis2(q[C], q[D])));
        }

        m = min(m, d);
        M = max(M, d);
    }
    cout << fixed << setprecision(20) << m << '\n'
         << M << '\n';
}