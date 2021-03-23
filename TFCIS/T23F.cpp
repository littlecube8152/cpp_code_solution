#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll n, a[200005], absr = _INFINITY, r = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i += 2)
        r += a[i];
    absr = abs(r);

    for (int i = n; i >= 1; i--)
    {
        if (i % 2)
            r += a[i];
        else
            r -= a[i];
        if (abs(r) < absr)
            absr = abs(r);
    }

    cout << absr << '\n';
}