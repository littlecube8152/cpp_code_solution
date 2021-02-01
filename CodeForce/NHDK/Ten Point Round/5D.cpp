#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, a[2000], d;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n <= 2)
    {
        cout << "Yes\n";
        return;
    }
    d = a[1] - a[0];
    for (int i = 2; i < n; i++)
        if (a[i] - a[i - 1] != d)
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

signed main()
{
    ll q;
    cin >> q;
    while (q--)
        solve();
}