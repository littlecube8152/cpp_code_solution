#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

ll N, x[2000006], y[2000006], ans = 1e18;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> x[i];
    for (int i = 1; i <= N; i++)
        cin >> y[i];
    x[0] = -1e11;
    x[N + 1] = 1e11;
    ll cur = 0;
    deque<pll> dq; // start, copy
    for (int i = 1; i <= N; i++)
    {
        if (cur < y[i])
            dq.push_back(pll(x[i - 1] + 1, y[i] - cur));
        else if (cur > y[i])
        {
            ll ps = cur - y[i];
            while (ps)
            {
                ans = min(ans, x[i] - dq.front().F - 1);
                if (ps < dq.front().S)
                {
                    dq.front().S -= ps;
                    break;
                }
                else 
                {
                    ps -= dq.front().S;
                    dq.pop_front();
                }
            }
        }
        cur = y[i];
    }
    cout << (ans >= 1e10 ? -1 : ans) << '\n';
}