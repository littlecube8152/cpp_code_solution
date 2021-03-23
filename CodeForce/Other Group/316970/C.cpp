#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// 10/100

int q;
pair<double, double> p[10];

double dis(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt((double)(p1.first - p2.first) * (double)(p1.first - p2.first) + (double)(p1.second - p2.second) * (double)(p1.second - p2.second));
}

signed main()
{
    cin >> q;
    for (int i = 1; i <= q + 3; i++)
        cin >> p[i].first >> p[i].second;
    double s = (dis(p[1], p[2]) + dis(p[2], p[3]) + dis(p[1], p[3])) / 2.0;

    if (q == 1)
    {
        sort(p + 1, p + 5);
        cout << fixed << setprecision(0) << dis(p[1], p[2]) * dis(p[1], p[3]) / 2 << '\n';
        cout << dis(p[1], p[2]) * dis(p[1], p[3]) << '\n';
    }
    else
        cout << fixed << setprecision(0) << sqrt(s * (s - dis(p[1], p[2])) * (s - dis(p[2], p[3])) * (s - dis(p[1], p[3]))) << '\n';
}