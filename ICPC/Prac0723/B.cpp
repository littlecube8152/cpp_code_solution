#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define double long double
#define ll long long
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

const double eps = 1e-9;

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

pdd rescale(pdd p, double l)
{
    double scale = l / sqrt(dot(p, p));
    return pdd(p.F * scale, p.S * scale);
}

const int c = 10000;
const double pi = acosl(-1);
int x[505], y[505], r[505];
map<pdd, int> circ;
map<pdd, double> angle;

int n;

bool checkline(pdd p, pdd q)
{
    // no intersections, and all lies on one side
    // cerr << "check " << p.F << ' ' << p.S << "  " << q.F << ' ' << q.S << '\n';
    int sign = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(cross(pdd(x[i], y[i]), p, q)) / sqrt(dis2(p, q)) * 1.0001 < r[i] - eps)
        {
            // cerr << "inter circle " << i << " with distance " << abs(cross(pdd(x[i], y[i]), p, q)) / sqrt(dis2(p, q)) <<'\n';
            return 0;
        }
        if (ori(p, q, pdd(x[i], y[i])) < 0)
            sign |= 1;
        else
            sign |= 2;
    }
    return sign < 3;
}

signed main()
{
    cin >> n;
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
    vector<pdd> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
        r[i] += 10;
    }
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (sqrt(dis2(pdd(x[i], y[i]), pdd(x[j], y[j]))) <= abs(r[i] - r[j]) + eps)
                {
                    if (r[i] <= r[j])
                        x[i] = x[n], y[i] = y[n], r[i] = r[n];
                    else
                        x[j] = x[n], y[j] = y[n], r[j] = r[n];
                    flag = 1;
                    goto why;
                }
    why:
        if (flag)
            n--;
    }

    if (n == 1)
    {
        cout << 2.0 * r[1] * pi << '\n';
        return 0;
    }
    if (n == 0)
    {
        cout << 0.0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            // assume i has a bigger radius
            if (make_pair(r[i], i) > make_pair(r[j], j))
            {
                // vector r1r2
                pdd r12 = pdd(x[j] - x[i], y[j] - y[i]);
                double d = sqrt(dot(r12, r12));
                if (d < eps)
                    continue;
                // difference of radius
                double dr12 = r[i] - r[j];
                double cosa = dr12 / d;
                assert(cosa <= 1.0);
                double sina = 1.0 - cosa * cosa;
                // roatate vector r1r2 by a and -a:
                pdd v1 = pdd(r12.F * cosa + r12.S * sina,
                             r12.F * -sina + r12.S * cosa),
                    v2 = pdd(r12.F * cosa + r12.S * -sina,
                             r12.F * sina + r12.S * cosa);
                pdd pi1 = pdd(x[i], y[i]) + rescale(v1, r[i]),
                    pi2 = pdd(x[i], y[i]) + rescale(v2, r[i]),
                    pj1 = pdd(x[j], y[j]) + rescale(v1, r[j]),
                    pj2 = pdd(x[j], y[j]) + rescale(v2, r[j]);
                if (checkline(pi1, pj1))
                {
                    v.emplace_back(pi1);
                    v.emplace_back(pj1);
                }
                if (checkline(pi2, pj2))
                {
                    v.emplace_back(pi2);
                    v.emplace_back(pj2);
                }
                circ[pi1] = i;
                circ[pi2] = i;
                circ[pj1] = j;
                circ[pj2] = j;
            }
    vector<pdd> u;
    for (auto p : v)
    {
        bool pass = 1;
        for (int i = 1; i <= n; i++)
            if (dis2(p, pdd(x[i], y[i])) + eps < r[i] * r[i])
                pass = 0;
        if (pass)
            u.emplace_back(p);
    }
    v = convex(u);
    n = (int)v.size();
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        pdd p = v[i], q = v[(i + 1) % n];
        if (circ[p] == circ[q])
        {
            int j = circ[p];
            cerr << j << ' ';
            double a1 = atan2l(p.S - y[j], p.F - x[j]), a2 = atan2l(q.S - y[j], q.F - x[j]);
            if (a1 < a2)
                a2 -= 2.0 * pi;
            double a = a1 - a2;
            ans += r[j] * a;
        }
        else
            ans += sqrtl(dis2(p, q));
    }
    cout << ans << '\n';
}