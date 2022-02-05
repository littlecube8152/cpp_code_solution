#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, arr[200005], res[200005];
vector<ll> dp;
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = ((i + 1) * m) - arr[i];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
            continue;
        int pos = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (pos == dp.size())
            dp.emplace_back(arr[i]);
        else
            dp[pos] = arr[i];
        res[i] = dp.size();
    }
    cout << n - dp.size() << '\n';
}