#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define pb(x) emplace_back(x)
using namespace std;

typedef pair<double, double> pdd;
typedef pair<pll, pll> Line;
pll operator+(pll a, pll b)
{
    return pll(a.X + b.X, a.Y + b.Y);
}
pll operator-(pll a, pll b)
{
    return pll(a.X - b.X, a.Y - b.Y);
}
pdd operator-(pdd a, pll b)
{
    return pdd(a.X - b.X, a.Y - b.Y);
}
pll operator*(pll a, ll b)
{
    return pll(a.X * b, a.Y * b);
}
pll operator/(pll a, ll b)
{
    return pll(a.X / b, a.Y / b);
}
pdd operator/(pll a, double b)
{
    return pdd(a.X / b, a.Y / b);
}
double dot(pdd a, pdd b)
{
    return a.X * b.X + a.Y * b.Y;
}
ll cross(pll a, pll b)
{
    return a.X * b.Y - a.Y * b.X;
}
double abs2(pdd a)
{
    return dot(a, a);
}
int sign(ll a)
{
    return a == 0 ? 0 : a > 0 ? 1
                              : -1;
}
int ori(pll a, pll b, pll c)
{
    return sign(cross(b - a, c - a));
}
bool collinearity(pll p1, pll p2, pll p3)
{
    return sign(cross(p1 - p3, p2 - p3)) == 0;
}
bool btw(pll p1, pll p2, pll p3)
{
    if (!collinearity(p1, p2, p3))
        return 0;
    return sign(dot(p1 - p3, p2 - p3)) <= 0;
}
bool seg_intersect(pll p1, pll p2, pll p3, pll p4)
{
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);
    if (a123 == 0 && a124 == 0)
        return btw(p1, p2, p3) || btw(p1, p2, p4) ||
               btw(p3, p4, p1) || btw(p3, p4, p2);
    return a123 * a124 <= 0 && a341 * a342 <= 0;
}
pdd intersect(pll p1, pll p2, pll p3, pll p4)
{
    ll a123 = cross(p2 - p1, p3 - p1);
    ll a124 = cross(p2 - p1, p4 - p1);
    return (p4 * a123 - p3 * a124) / double(a123 - a124); // C^3 / C^2
}
pll perp(pll p1)
{
    return pll(-p1.Y, p1.X);
}
int cmp(pll a, pll b, bool same = true)
{
#define is_neg(k) (sign(k.Y) < 0 || (sign(k.Y) == 0 && sign(k.X) < 0))
    int A = is_neg(a), B = is_neg(b);
    if (A != B)
        return A < B;
    if (sign(cross(a, b)) == 0)
        return same ? abs2(a) < abs2(b) : -1;
    return sign(cross(a, b)) > 0;
}

pll area_pair(Line a, Line b)
{
    return pll(cross(a.Y - a.X, b.X - a.X), cross(a.Y - a.X, b.Y - a.X));
}
bool isin(Line l0, Line l1, Line l2)
{
    // Check inter(l1, l2) strictly in l0
    auto [a02X, a02Y] = area_pair(l0, l2);
    auto [a12X, a12Y] = area_pair(l1, l2);
    if (a12X - a12Y < 0)
        a12X *= -1, a12Y *= -1;
    return (__int128)a02Y * a12X - (__int128)a02X * a12Y > 0; // C^4
}
/* Having solution, check size > 2 */
/* --^-- Line.X --^-- Line.Y --^-- */
vector<Line> halfPlaneInter(vector<Line> arr)
{
    sort(ALL(arr), [&](Line a, Line b) -> int
         {
    if (cmp(a.Y - a.X, b.Y - b.X, 0) != -1)
      return cmp(a.Y - a.X, b.Y - b.X, 0);
    return ori(a.X, a.Y, b.Y) < 0; });
    deque<Line> dq(1, arr[0]);
    for (auto p : arr)
    {
        if (cmp(dq.back().Y - dq.back().X, p.Y - p.X, 0) == -1)
            continue;
        while (SZ(dq) >= 2 && !isin(p, dq[SZ(dq) - 2], dq.back()))
            dq.pop_back();
        while (SZ(dq) >= 2 && !isin(p, dq[0], dq[1]))
            dq.pop_front();
        dq.pb(p);
    }
    while (SZ(dq) >= 3 && !isin(dq[0], dq[SZ(dq) - 2], dq.back()))
        dq.pop_back();
    while (SZ(dq) >= 3 && !isin(dq.back(), dq[0], dq[1]))
        dq.pop_front();
    return vector<Line>(ALL(dq));
}

int N, W, H;
pll p[2005];

signed main()
{
    double ans = 0;
    cin >> N >> W >> H;
    W *= 2, H *= 2;
    vector<Line> edge = {{{0, 0}, {W, 0}}, {{W, 0}, {W, H}}, {{W, H}, {0, H}}, {{0, H}, {0, 0}}};
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].X >> p[i].Y;
        p[i].X *= 2, p[i].Y *= 2;
    }
    for (int i = 1; i <= N; i++)
    {
        vector<Line> inter = edge;
        for (int j = 1; j <= N; j++)
            if (i != j)
            {
                pll mid = p[i] + p[j];
                mid.X /= 2, mid.Y /= 2;
                pll side = p[j] - p[i];
                side = pll(-side.Y, side.X); // rotate by 90
                inter.emplace_back(make_pair(mid, mid + side));
            }
        inter = halfPlaneInter(inter);
        int K = SZ(inter);
        // cerr << p[i].X << ' ' << p[i].Y << '\n';
        for (int j = 0; j < K; j++)
        {
            // cerr << inter[j].X.X << ' ' << inter[j].X.Y << ' ' << inter[j].Y.X << ' ' << inter[j].Y.Y << '\n';
            ans = max(ans, sqrt(abs2(intersect(inter[j].X, inter[j].Y, inter[(j + 1) % K].X, inter[(j + 1) % K].Y) - p[i])));
        }
    }
    cout << fixed << setprecision(100) << ans / 2 << '\n';
}