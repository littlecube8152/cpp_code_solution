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

int n;
pii arr[100005];
vector<int> dp;

signed main()
{
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].F >> arr[i].S;
    sort(arr, arr + n, greater<pii>());
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(dp.begin(), dp.end(), arr[i].S) - dp.begin();
        if(pos == dp.size())
            dp.emplace_back(arr[i].S);
        else
            dp[pos] = arr[i].S;
    }
    cout << dp.size() << '\n';
}