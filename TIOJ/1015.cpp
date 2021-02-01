#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        ll i = min(n, m);
        cout << (i) * (i + 1) * (2 * i + 1) / 6 - (i) * (i + 1) / 2 * (m + n) + (i + 1) * m * n << '\n';
    }
}