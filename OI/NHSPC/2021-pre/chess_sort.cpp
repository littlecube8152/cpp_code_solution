#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n;
pii arr[1000005];
ll ans;

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].F >> arr[i].S;

    sort(arr + 1, arr + 1 + n, [](pii p1, pii p2)
         { return p1.F + p1.S < p2.F + p2.S; });
    for (int i = 1; i < n; i++)
        if (arr[i].F + arr[i].S == arr[i + 1].F + arr[i + 1].S)
            ans++;

    sort(arr + 1, arr + 1 + n, [](pii p1, pii p2)
         { return p1.F - p1.S < p2.F - p2.S; });
    for (int i = 1; i < n; i++)
        if (arr[i].F - arr[i].S == arr[i + 1].F - arr[i + 1].S)
            ans++;

    sort(arr + 1, arr + 1 + n, [](pii p1, pii p2)
         { return p1.F < p2.F; });
    for (int i = 1; i < n; i++)
        if (arr[i].F == arr[i + 1].F)
            ans++;

    sort(arr + 1, arr + 1 + n, [](pii p1, pii p2)
         { return p1.S < p2.S; });
    for (int i = 1; i < n; i++)
        if (arr[i].S == arr[i + 1].S)
            ans++;
    cout << ans << '\n';
}