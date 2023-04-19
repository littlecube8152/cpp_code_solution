// Problem B fake solution
// Expected: 10, Actual: 39
// Bug(s): This code only checks previous 100 positions

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, x, m, a[1000006], c[1000006], ans[1000006];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    n++;
    c[n] = m;

    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1e15;
        for (int j = max(0, i - 100); j < i; j++)
            if (c[j] + x >= c[i])
                ans[i] = min(ans[j] + a[j], ans[i]);
    }
    cout << (ans[n] >= 1e15 ? -1 : ans[n]) << '\n';
}
