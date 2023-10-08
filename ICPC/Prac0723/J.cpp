#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll u[20], r[20], t[20], a[20], b[20];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 10; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= 10; i++)
        cin >> u[i] >> r[i] >> t[i];
    ll cur = 0;
    for (int why = 1; why <= 3; why++)
        for (int i = 1; i <= 10; i++)
        {
            if (cur < t[i])
            {
                t[i] = max(t[i], cur + a[i]);
                cur += a[i] + b[i];
            }
            else
            {
                ll d = cur - t[i];
                if (d % (u[i] + r[i]) < u[i])
                    cur += (u[i] - d % (u[i] + r[i]));
                ll nxt = t[i] + (d / (u[i] + r[i]) + 1) * (u[i] + r[i]);
                if(cur + a[i] >= nxt)
                    t[i] = cur + a[i];
                cur += a[i] + b[i];
            }
            // cout << u[i] << ' ' << r[i] << ' ' << t[i] << '\n';
        }
    cout << cur - b[10] << '\n';
}