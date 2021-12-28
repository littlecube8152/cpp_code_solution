#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pii vec(pii a, pii b)
{
    return make_pair(b.F - a.F, b.S - a.S);
}

ll cross(pii a, pii b)
{
    return a.F * b.S - a.S * b.F;
}

ll sign(pii a, pii b)
{
    ll cr = cross(a, b);
    if (cr == 0)
        return (b.F * b.F + b.S * b.S > a.F * a.F + a.S * a.S ? 1 : -1);
    else
        return cr / abs(cr);
}

vector<pii> p;
ll n;
deque<pii> hull;

void build_hull(int i)
{
    while (hull.size() > 1 && sign(vec(*(hull.end() - 2), hull.back()), vec(*(hull.end() - 2), p[i])) > 0)
        hull.pop_back();
    hull.push_back(p[i]);
}
signed main()
{
    cin >> n;
    p.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p.begin() + 1, p.end());
    hull.push_back(p[1]);
    for (ll i = 2; i <= n; i++)
        build_hull(i);
    for (ll i = n - 1; i >= 1; i--)
        build_hull(i);
    cout << hull.size() - 1 << '\n';
    //for (ll i = 0; i < hull.size(); i++)
    //cout << "H " << i << " " << hull[i].F << " " << hull[i].S << '\n';
}