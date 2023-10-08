#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

pll operator+(pll p, pll q)
{
    return pll(p.F + q.F, p.S + q.S);
}

pll operator-(pll p)
{
    return pll(-p.F, -p.S);
}

ll cross(pll p, pll q)
{
    return p.F * q.S - p.S * q.F;
}

int side(pll p)
{
    return p.S < 0 || (p.S == 0 && p.F < 0);
}


int n, vis[300005];
vector<pair<pll, int>> v;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == b && c == d)
            continue;
        v.emplace_back(make_pair(pll(a - b, c - d), i));
        v.emplace_back(make_pair(pll(b - a, d - c), -i));
    }
    sort(v.begin(), v.end(), [&](auto p, auto q)
         {  int a = side(p.F), b = side(q.F);
            if(a != b) return a < b;
            return cross(p.F, q.F) > 0; });

    pll p(0, 0);
    for (auto [q, i] : v)
        if(i < 0 && !vis[-i])
            p = p + -q;
        else
            vis[abs(i)] = 1;

    double ans = 0;
    for (auto [q, _] : v)
    {
        p = p + q;
        ans = max(ans, double(p.F) * p.F + double(p.S) * p.S);
    }
    cout << fixed << setprecision(0) << ans << '\n';
}