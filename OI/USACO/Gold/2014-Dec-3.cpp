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

ll n, t;
pll arr[100005];
vector<ll> dp;
signed main()
{
    fast;
    ifstream cin("cowjog.in");
    ofstream cout("cowjog.out");
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].F >> arr[i].S;
        arr[i].S = (arr[i].F + t * arr[i].S);
    }
    sort(arr, arr + n, greater<pll>());
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(dp.begin(), dp.end(), arr[i].S) - dp.begin();
        if (pos == dp.size())
            dp.emplace_back(arr[i].S);
        else
            dp[pos] = arr[i].S;
    }
    cout << dp.size() << '\n';
}