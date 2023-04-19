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
   
    deque<pll> dq;
    dq.emplace_front(pll(0, 0));
    for (int i = 1; i <= n; i++)
    {
        while(!dq.empty() && dq.back().F + x < c[i])
            dq.pop_back();
        if(dq.empty())
        {
            cout << -1 << '\n';
            return 0;
        }
        ans[i] = dq.back().S;
        while(!dq.empty() && dq.front().S >= ans[i] + a[i])
            dq.pop_front();
        dq.emplace_front(pll(c[i], ans[i] + a[i]));
    }
    cout << ans[n] << '\n';
}
