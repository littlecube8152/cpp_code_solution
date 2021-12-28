#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    int n, r = 0, cr = 0;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x > 0)
            cr++;
        if (x <= 0)
        {
            r = max(cr, r);
            cr = 0;
        }
    }
    r = max(cr, r);
    cout << r;
}