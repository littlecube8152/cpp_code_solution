#include <bits/stdc++.h>
using namespace std;
#define double long double
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

const double eps = 1e-9, pi = acos(-1);

pdd operator+(pdd p1, pdd p2)
{
    return pdd(p1.F + p2.F, p1.S + p2.S);
}
pdd operator-(pdd p, pdd q)
{
    return pdd(p.F - q.F, p.S - q.S);
}
pdd operator*(pdd p, double c)
{
    return pdd(c * p.F, c * p.S);
}
pdd operator/(pdd p, double c)
{
    return pdd(p.F / c, p.S / c);
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

int n, type[100005];
pdd p[100005], c = pdd(0, 0);
double ans[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;
    double A = 0.0;
    for (int i = 1; i + 1 < n; i++)
    {
        c = c + (p[0] + p[i] + p[i + 1]) / 3.0 * abs(cross(p[0], p[i], p[i + 1]));
        A += abs(cross(p[0], p[i], p[i + 1]));
    }
    c = c / A;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        if (dot(c - p[i], p[j] - p[i]) < -eps)
            type[i] = -1;
        else if (dot(c - p[j], p[i] - p[j]) < -eps)
            type[i] = 1;
        ans[i] = acosl(dot(p[i] - c, p[j] - c) / sqrtl(dot(p[i] - c, p[i] - c) * dot(p[j] - c, p[j] - c)));
    }
    for (int t = 0; t <= 1; t++)
    {
        for (int i = 0; i < n; i++)
            if (type[i] == 1)
            {
                ans[(i + 1) % n] += ans[i];
                ans[i] = 0;
            }
        for (int i = n - 1; i >= 0; i--)
            if (type[i] == -1)
            {
                ans[(i + n - 1) % n] += ans[i];
                ans[i] = 0;
            }
    }
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(15) << ans[i] / (2.0 * pi) << '\n';
}