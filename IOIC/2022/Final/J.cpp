#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define ll long long
#define int long long
#define F first
#define S second
#define pll pair<ll, ll>

int N;
double ans = 1e9;
pll p[300005];

struct line
{
    double a, b, c, aabb;
    double operator()(pll p)
    {
        return (a * p.F + b * p.S - c) / aabb;
    }
};

const double eps = 1e-9;

line twoPoint(pll p1, pll p2)
{
    return line{double(p1.S - p2.S), -double(p1.F - p2.F), double(p2.F * p1.S) - double(p2.S * p1.F)};
}

int sgn(ll a, ll b, ll c, ll d)
{
    ll res = a * d - b * c;
    if (res < 0)
        return -1;
    else if (res == 0)
        return 0;
    return 1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(20);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    sort(p + 1, p + 1 + N);
    vector<pll> convex;
    for (int i = 1; i <= N; i++)
    {
        while (convex.size() >= 2 &&
               sgn(convex.back().F - convex[convex.size() - 2].F, convex.back().S - convex[convex.size() - 2].S,
                   p[i].F - convex[convex.size() - 2].F, p[i].S - convex[convex.size() - 2].S) >= 0)
            convex.pop_back();
        convex.emplace_back(p[i]);
    }
    for (int i = N - 1, j = convex.size(); i >= 1; i--)
    {
        while (convex.size() >= j + 1 &&
               sgn(convex.back().F - convex[convex.size() - 2].F, convex.back().S - convex[convex.size() - 2].S,
                   p[i].F - convex[convex.size() - 2].F, p[i].S - convex[convex.size() - 2].S) >= 0)
            convex.pop_back();
        convex.emplace_back(p[i]);
    }
    //assert(convex.back() == p[1]);
    convex.pop_back();
    if (convex.size() <= 2)
    {
        cout << 0.0 << '\n';
        return 0;
    }
    int M = convex.size();
    for (int i = 0, j = 1; i < M; i++)
    {
        line L = twoPoint(convex[i], convex[(i + 1) % M]);
        L.aabb = sqrt(L.a * L.a + L.b * L.b);
        while (abs(L(convex[j])) < abs(L(convex[(j + 1) % M])))
            j = (j + 1) % M;
        ans = min(ans, abs(L(convex[j])));
    }
    cout << ans / 2.0 << '\n';
}

/*
10
1 3
4 2
3 6
7 3
4 5
2 6
4 7
9 1
5 2
3 4
*/