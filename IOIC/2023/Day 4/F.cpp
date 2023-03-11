#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const double eps = 1e-10;
pll operator+(pll p, pll q)
{
    return pll(p.F + q.F, p.S + q.S);
}
pll operator-(pll p, pll q)
{
    return pll(p.F - q.F, p.S - q.S);
}
pll operator*(pll p, double d)
{
    return pll(p.F * d, p.S * d);
}
pll operator/(pll p, double d)
{
    return pll(p.F / d, p.S / d);
}
double cross(pll p1, pll p2)
{
    return p1.F * p2.S - p1.S * p2.F;
}
double dot(pll p1, pll p2)
{
    return p1.F * p2.F + p1.S * p2.S;
}
double cross(pll p, pll q1, pll q2)
{
    return cross(q1 - p, q2 - p);
}
pll intersect(pll p1, pll p2, pll p3, pll p4)
{
    double a123 = cross(p1, p2, p3),
           a124 = -cross(p1, p2, p4);
    return (p4 * a123 + p3 * a124) / (a123 + a124);
}
int ori(pll p, pll q1, pll q2)
{
    double c = cross(p, q1, q2);
    return (c > eps ? 1 : (c < eps ? -1 : 0));
}

int quadurant(pll p)
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

struct angle_cmp
{
    bool operator()(pll p1, pll p2) const
    {
        if (quadurant(p1) != quadurant(p2))
            return quadurant(p1) < quadurant(p2);
        return p1.S * p2.F < p2.S * p1.F;
    };
} acmp;

int N;
pll p[2005];
map<pll, int, angle_cmp> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dir = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;

    vector<pair<pll, int>> vec;
    vector<ll> ans;
    int cur = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j)
            {
                pll v = p[j] - p[i];
                int cost;
                if (quadurant(v) <= 2)
                {
                    cur += (j < i);
                    cost = (j < i ? -1 : 1);
                }
                else
                    cost = (j < i ? -1 : 1);
                vec.emplace_back(make_pair(v, cost));
            }
    sort(vec.begin(), vec.end(), [&](pair<pll, int> p1, pair<pll, int> p2)
         { return acmp(p1.F, p2.F); });

    pll pr = pll(0, 0);
    for (auto [p, val] : vec)
    {
        if (acmp(pr, p))
        {
            pr = p;
            ans.emplace_back(cur);
        }
        cur += val;
    }
    sort(ans.begin(), ans.end(), greater<>());
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int k;
        cin >> k;
        cout << ans[k - 1] << '\n';
    }
}