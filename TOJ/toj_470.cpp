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
    int n;
    while (cin >> n)
    {
        ll a[2] = {0}, b[2] = {0}, *x = a, *y = b, k = 0;
        while (n--)
        {
            cin >> k;
            y[0] = x[1] + k;
            y[1] = max(x[0], x[1]);
            swap(x, y);
        }
        cout << max(x[0], x[1]) << '\n';
    }
}

