#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        if (k % (m + 1) == 0)
        {
            if (((n % (k + 1)) % (m + 1)) == 0 && ((n % (k + 1))) != k)
                cout << "Shoko\n";
            else
                cout << "Rem\n";
        }
        else
        {
            if ((n % (m + 1)) == 0)
                cout << "Shoko\n";
            else
                cout << "Rem\n";
        }
    }
}