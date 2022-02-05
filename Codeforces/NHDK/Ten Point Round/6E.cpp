#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    ll n, m, r = 0, a[100005], b[100005] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);


    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        b[x]++;
        b[y]++;
    }

    sort(b + 1, b + n + 1, [](int a, int b) { return a > b; });

    for (int i = 1; i <= n; i++)
        r += a[i] * b[i];
    cout << r << '\n';

}