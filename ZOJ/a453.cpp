#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t, a, b, c, D;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        D = b * b - 4 * a * c;
        if (D >= 0)
            if (sqrt(D) - floor(sqrt(D)) <= 0.00001)
                cout << "Yes\n";
            else
                cout << "No\n";
        else
            cout << "No\n";
    }
}