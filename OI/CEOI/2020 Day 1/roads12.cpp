#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
ll dx, dy;
pll p[200005];
vector<int> v;
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[2 * i - 1].F >> p[2 * i - 1].S >> p[2 * i].F >> p[2 * i].S;
    dx = p[2].F - p[1].F;
    dy = p[2].S - p[1].S;
    for (int i = 1; i <= N; i++)
        v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i1, int i2)
         {
             if (p[i1 * 2].F * dy - p[i1 * 2].S * dx != p[i2 * 2].F * dy - p[i2 * 2].S * dx)
                 return p[i1 * 2].F * dy - p[i1 * 2].S * dx < p[i2 * 2].F * dy - p[i2 * 2].S * dx;
             else
                 return p[i1 * 2] < p[i2 * 2];
         });
    for (int i = 1; i < N; i++)
        cout << max(p[2 * v[i - 1] - 1], p[2 * v[i - 1]]).F << " " << max(p[2 * v[i - 1] - 1], p[2 * v[i - 1]]).S << " " << min(p[2 * v[i] - 1], p[2 * v[i]]).F << " " << min(p[2 * v[i] - 1], p[2 * v[i]]).S << '\n';
}