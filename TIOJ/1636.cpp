#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#pragma pack(1)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, a[4], res;
signed main()
{
    fast;
    cin >> n >> k >> a[0] >> a[1];

    n = n - 2, k++;
    a[3] = a[0] * ((k + 1) >> 1LL) + a[1] * (k >> 1LL);
    res = a[3];

    for (int i = n; i > 0 && k--; i--)
    {
        cin >> a[2];
        a[3] = a[3] + (k >> 1LL) * (a[2] - a[0]);
        res = max(res, a[3]);
        a[0] = a[1], a[1] = a[2];
    }

    cout << res << '\n';
}