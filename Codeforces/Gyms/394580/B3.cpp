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
    ans[0] = -1;
    c[n] = m;
   
    for (int i = 1, j = 0; i <= n; i++)
    {
        while(c[j] + x < c[i])
            j++;
        if(i == j)
        {
            cout << -1 << '\n';
            return 0;
        }
        ans[i] = ans[j] + 1;
    }
    cout << ans[n] << '\n';
}
