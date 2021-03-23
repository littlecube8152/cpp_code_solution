//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, bit[200005], ans;
pii arr[200005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].F;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].S;
    for (int i = 1; i <= n; i++)
    {
        ll k = arr[i].F - 1, val = 0;
        if (k > 0)
            for (; k > 0; k -= (k & -k))
                val = max(val, bit[k]);
        val += arr[i].S, k = arr[i].F, ans = max(ans, val);
        for (; k <= n; k += (k & -k))
            bit[k] = max(val, bit[k]);
    }
    cout << ans << '\n';
}