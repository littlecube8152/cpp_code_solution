#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

double p, q, r, s, t, u;
double solve(double L, double R)
{
    if (abs(L - R) <= 0.0000000001)
        return L;

    double mid = (L + R) / 2.0;
    double fmid = p * exp(-mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u;
    if (fmid < 0)
        return solve(L, mid);
    else
        return solve(mid, R);
}

int main()
{
    fast;
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        double ans = solve(-0.1, 1.1);
        if (ans >= -0.00005 && ans <= 1.00004)
            cout << fixed << setprecision(4) << abs(ans) << '\n';
        else
           cout << "No solution\n";
    }
}