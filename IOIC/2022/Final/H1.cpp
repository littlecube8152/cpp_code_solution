#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define ll long long
#define int long long
#define F first
#define S second
#define pll pair<ll, ll>

int N;
double ans = 0;
pll p[205];

struct line
{
    double a, b, c;
    double dis(pll p)
    {
        return (a * p.F + b * p.S + c) / sqrtl(a * a + b * b);
    }
};

line twoPoint(pll p1, pll p2)
{
    return line{double(p1.S - p2.S), -double(p1.F - p2.F), double(p2.F * p1.S) - double(p2.S * p1.F)};
}

const double eps = 1e-12;

signed main()
{
    cin >> N;
    assert(N <= 200);
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            line L = twoPoint(p[i], p[j]);
            cout << i << " " << j << " " << L.a << " " << L.b << " " << L.c << '\n';
            double pos = 1e15, neg = -1e15;
            for (int k = 1; k <= N; k++)
                if (k != i && k != j)
                {
                    double res = L.dis(p[k]);
                    if (res < eps)
                        neg = max(neg, res);
                    if (res > -eps)
                        pos = min(pos, res);
                }
            cout << pos << " " << neg << '\n';
            if(pos > 1e14)
                pos = 0;
            if(neg < -1e14)
                neg = 0;
            ans = max({ans, pos, -neg});
        }
    cout << fixed << setprecision(20) << ans << '\n';
}