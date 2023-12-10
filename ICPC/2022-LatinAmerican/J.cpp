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

struct linequery
{
    #define pllll tuple<ll, ll, ll, ll>
    int n;
    vector<int> id;
    vector<ll> s;
    vector<pll> l;
    vector<pllll> event;
    void clear()
    {
        n = 0;
        s.clear();
        l.clear();
        event.clear();
    }
    void insert(int i, int S, pll p)
    {
        id.emplace_back(i);
        s.emplace_back(S);
        l.emplace_back(p);
    }
    void query(ll U, ll A, ll B)
    {
        event.emplace_back(U, 1, A, B);
    }
    

} lines


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