#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, ans, arr[200005];
signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ans += max(arr[i - 1] - arr[i], 0LL);
        arr[i] = max(arr[i], arr[i - 1]);
    }
    cout << ans;
}