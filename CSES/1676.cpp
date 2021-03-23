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

int n, m, dsu[100005], rk[100005], block, size;

signed main()
{
    fast;
    function<int(int)> fnd;
    fnd = [&](int x) { return (x == dsu[x] ? x : dsu[x] = fnd(dsu[x])); };
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dsu[i] = i, rk[i] = 1;
    block = n, size = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y, rx, ry;
        cin >> x >> y;
        rx = fnd(x), ry = fnd(y);
        if (rx != ry)
            block--, rk[ry] = rk[rx] + rk[ry], dsu[rx] = ry, size = max(size, rk[ry]);
        cout << block << " " << size << '\n';
    }
}