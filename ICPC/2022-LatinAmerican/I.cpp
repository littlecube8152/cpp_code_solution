#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, m, ans, a[105][105], x[10005], y[10005];
bitset<10005> b[10005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], x[a[i][j]] = i, y[a[i][j]] = j;
    for (int i = n * m; i >= 1; i--)
    {
        b[i][i] = i;
        auto check = [&](int j)
        {
            if (j > i)
                b[i] |= b[j];
        };
        int p = x[i], q = y[i];
        check(a[p + 1][q]);
        check(a[p - 1][q]);
        check(a[p][q + 1]);
        check(a[p][q - 1]);
        ans = max(ans, (int)b[i].count());
    }
            

    cout << ans << '\n';
}