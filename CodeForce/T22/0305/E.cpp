//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, r;
vector<pii> v;
vector<int> ans;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.emplace_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        if(m >= v[i].first)
            m -= v[i].first, ans.emplace_back(v[i].second);
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << " ";
}