#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll Q, a[1000005], ans, idx;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> Q;
    a[0] = ans = 1;
    while(Q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            cin >> t;
            a[++idx] = a[t] + 1;
            ans = max(ans, a[idx]);
        }
        else
            cout << ans << '\n';    
    }
}
