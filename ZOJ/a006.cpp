#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b * b - 4 * a * c > 0)
        cout << "Two different roots x1=" << (-b + (int)sqrt(b * b - 4 * a * c)) / (2 * a) << " , x2=" << (-b - (int)sqrt(b * b - 4 * a * c)) / (2 * a) << '\n';
    if (b * b - 4 * a * c == 0)
        cout << "Two same roots x=" << -b / (2 * a) << '\n';
    if (b * b - 4 * a * c < 0)
        cout << "No real root\n";
}