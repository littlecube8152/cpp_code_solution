//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

short n, m, k, dsu[10001], x, y, rx, ry;

void init()
{
    for (short i = 1; i <= n; i++)
        dsu[i] = i;
}

short root(short x)
{
    if (x == dsu[x])
        return x;
    return root(dsu[x]);
}

signed main()
{
    fast;
    while (cin >> n >> m)
    {
        init();
        while (m--)
        {

            cin >> x >> y;
            rx = root(x);
            ry = root(y);
            if (rx > ry)
                dsu[rx] = ry;
            if (rx < ry)
                dsu[ry] = rx;
        }
        cin >> k;
        cout << root(k) << '\n';
    }
}