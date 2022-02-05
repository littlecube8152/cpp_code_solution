#pragma GCC optimize("O3,unroll-loops")
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

int n, cnt, bit[1000005], pref[1000005], suf[1000005];
vector<int> v;

signed main()
{
    fast;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> u = v;
    sort(u.begin(), u.end());
    for (int &i : v)
        i = (lower_bound(u.begin(), u.end(), i) - u.begin()) + 1;

    map<int, int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp[v[i]]++;
        pref[i] = tmp[v[i]];
    }
    tmp.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        tmp[v[i]]++;
        suf[i] = tmp[v[i]];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = pref[i] - 1; j > 0; j -= (j & -j))
            cnt += bit[j];
        for (int j = suf[i]; j <= n; j += (j & -j))
            bit[j]++;
    }
    cout << cnt << '\n';
}