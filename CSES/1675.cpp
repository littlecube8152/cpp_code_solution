#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(_x) emplace_back(_x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dsu[100005], ans;
vector<pair<int, pii>> v;
signed main()
{
    fast;
    function<int(int)> find;
    find = [&](int k) { return (k == dsu[k] ? k : dsu[k] = find(dsu[k])); };

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        dsu[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v.pb(make_pair(w, make_pair(x, y)));
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        int rx = find(i.S.F), ry = find(i.S.S);
        if (rx != ry)
            ans += i.F, dsu[rx] = ry, n--;
    }
    if (n == 1)
        cout << ans << '\n';
    else
        cout << "IMPOSSIBLE\n";
}