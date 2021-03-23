#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, bit[200005], ans;
vector<int> v, d;
signed main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    d = v;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; i++)
        v[i] = lower_bound(d.begin(), d.end(), v[i]) - d.begin() + 1;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = v[i]; j > 0; j -= (j & -j))
            res = max(res, bit[j]);
        res++;
        ans = max(ans, res);
        for (int j = v[i]; j <= n; j += (j & -j))
            bit[j] = max(bit[j], res);
    }
    cout << ans << '\n';
}