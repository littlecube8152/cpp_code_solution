#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    int n;
    while (cin >> n)
    {
        vector<pdd> v;
        double area = 0;
        v.resize(n + 1);
        for (int i = 0; i < n; i++)
            cin >> v[i].F >> v[i].S;
        v[n] = v[0];
        for (int i = 0; i < n; i++)
            area += double(v[i].F * v[i + 1].S - v[i].S * v[i + 1].F);
        cout << fixed << setprecision(2) << abs(area * 0.5) << '\n';
    }
}