#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll H, W, arr[50004];
ll ans;

signed main()
{
    cin >> H >> W;
    assert(H == 1);
    for (int j = 1; j <= W; j++)
        cin >> arr[j];
    for (ll i = 1; i < W;)
    {
        ll j = i + 1;
        while (j < W && (j == i || (arr[j + 1] - arr[j]) * (arr[i + 1] - arr[i]) > 0))
            j++;
        ans += (j - i + 1) * (j - i) / 2;
        i = j;
    }
    cout << ans + W << '\n';
}