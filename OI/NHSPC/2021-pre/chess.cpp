#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;




int n;
map<int, bool> a, b, c, d;
ll ans;

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (a[x])
            ans++;
        else
            a[x] = 1;
        if (b[y])
            ans++;
        else
            b[y] = 1;
        if (c[x + y])
            ans++;
        else
            c[x + y] = 1;
        if (d[x - y])
            ans++;
        else
            d[x - y] = 1;
    }
    cout << ans << '\n';
}