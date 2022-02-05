/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int n, q;
ll bit[200005];

void modify(int pos, int v)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += v;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void init()
{
    for (int i = 1; i <= n; i++)
        if (i + (i & -i) <= n)
            bit[i + (i & -i)] += bit[i];
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> bit[i];
    for (int i = n; i > 1; i--)
        bit[i] -= bit[i - 1];
    init();
    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            modify(b + 1, -u);
            modify(a, u);
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            cout << query(k) << '\n';
        }
    }
}
