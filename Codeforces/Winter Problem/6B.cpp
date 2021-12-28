#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

#define x first
#define y second
int main()
{
    cout << setprecision(14) << fixed;
    int n, r;
    vector<pair<double, double>> v;
    cin >> n >> r;
    while (n--)
    {
        double a, b = r;
        cin >> a;
        for (auto i : v)
        {
            if (abs(i.x - a) > 2 * r)
                continue;
            else
                b = max(sqrt(4 * r * r - abs(i.x - a) * abs(i.x - a)) + i.y, b);
        }
        cout << b << " ";
        v.emplace_back(make_pair(a, b));
    }
}