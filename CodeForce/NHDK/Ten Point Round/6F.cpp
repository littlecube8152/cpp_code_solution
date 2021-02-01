#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m = -1, b, r = 1000000000000000, oldi = -1;
set<ll> a;
signed main()
{

    cin >> n;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }

    b = n;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }
    r = min(r, b);
    for (ll i : a)
    {
        b += (i - oldi - 2);
        oldi = i;
        r = min(r, b);
    }
    cout << r << '\n';
}