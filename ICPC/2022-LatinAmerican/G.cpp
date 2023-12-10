#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

pll operator+(pll a, pll b)
{
    return pll(a.F + b.F, a.S + b.S);
}
pll operator-(pll a, pll b)
{
    return pll(a.F - b.F, a.S - b.S);
}
pll operator*(pll p, ll d)
{
    return pll(p.F * d, p.S * d);
}
pll operator/(pll p, ll d)
{
    return pll(p.F / d, p.S / d);
}
ll cross(pll p, pll q)
{
    return p.F * q.S - p.S * q.F;
}
ll dot(pll p, pll q)
{
    return p.F * q.F + p.S * q.S;
}
ll ori(pll a, pll p, pll q)
{
    ll c = cross(p - a, q - a);
    return (c < 0 ? -1 : c == 0 ? 0
                                : 1);
}

void convex(vector<pll> &dots)
{
    sort(all(dots));
    vector<pll> hull(1, dots[0]);
    for (int ct = 0; ct < 2; ++ct, reverse(all(dots)))
        for (int i = 1, t = hull.size(); i < dots.size(); hull.emplace_back(dots[i++]))
            while (hull.size() > t && ori(hull.end()[-2], hull.back(), dots[i]) <= 0)
                hull.pop_back();
    hull.pop_back();
    hull.swap(dots);
}

vector<pll> minkowski(vector<pll> A, vector<pll> B)
{
    convex(A), convex(B);
    vector<pll> C(1, A[0] + B[0]), s1, s2;
    for (int i = 0; i < A.size(); i++)
        s1.emplace_back(A[(i + 1) % A.size()] - A[i]);
    for (int i = 0; i < B.size(); i++)
        s2.emplace_back(B[(i + 1) % B.size()] - B[i]);
    for (int i = 0, j = 0; i < A.size() || j < B.size();)
        if (j >= B.size() || (i < A.size() && cross(s1[i], s2[j]) >= 0))
            C.emplace_back(B[j % B.size()] + A[i++]);
        else
            C.emplace_back(A[i % A.size()] + B[j++]);
    convex(C);
    return C;
}

bool pointInConvex(vector<pll> &C, pll p)
{
    int a = 1, b = C.size() - 1, r = 1;
    if (ori(C[0], C[a], C[b]) > 0)
        swap(a, b);
    if (ori(C[0], C[a], p) >= r || ori(C[0], C[b], p) <= -r)
        return false;
    while (abs(a - b) > 1)
    {
        int c = (a + b) / 2;
        (ori(C[0], C[c], p) > 0 ? b : a) = c;
    }
    return ori(C[a], C[b], p) < r;
}

int M1, M2, N;
pll o1, o2;
vector<pll> p1, p2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> M1;
    p1.resize(M1);
    for (int i = 0; i < M1; i++)
        cin >> p1[i].F >> p1[i].S;
    cin >> M2;
    p2.resize(M2);
    for (int i = 0; i < M2; i++)
        cin >> p2[i].F >> p2[i].S;
    vector<pll> P1 = minkowski(p1, p2);
    
    for (int i = 0; i < M1; i++)
        p1[i] = p1[i] * 4;
    for (int i = 0; i < M2; i++)
        p2[i] = p2[i] * -2;
    vector<pll> P2 = minkowski(p1, p2);
    
    for (int i = 0; i < M1; i++)
        p1[i] = p1[i] / -2;
    for (int i = 0; i < M2; i++)
        p2[i] = p2[i] * -2;
    vector<pll> P3 = minkowski(p1, p2);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        pll p;
        cin >> p.F >> p.S;
        p = p * 2;
        if (pointInConvex(P1, p) || pointInConvex(P2, p) || pointInConvex(P3, p))
            cout << "Y";
        else
            cout << "N";
    }

    cout << '\n';
}