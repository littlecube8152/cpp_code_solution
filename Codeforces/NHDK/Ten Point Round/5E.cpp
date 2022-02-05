#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    int n, m, a[200005], b[200005];
    ll r = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n, [](int x, int y) { return x > y; });
    sort(b, b + m, [](int x, int y) { return x > y; });
    for (int i = 0, j = 0; i < m && j < n; j++)
    {
        if (b[i] >= a[j])
        {
            i++;
            r += (ll)a[j];
        }
    }
    cout << r << '\n';
}