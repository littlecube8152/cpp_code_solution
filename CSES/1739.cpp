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
ll bit[1005][1005], arr[1005][1005];
vector<pair<char, pii>> queries;

void modify(int x, int y, ll v)
{
    for (int i = x; i <= n; i += (i & -i))
        for (int j = y; j <= n; j += (j & -j))
            bit[i][j] += v;
}

ll query(int x, int y)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j))
            ans += bit[i][j];
    return ans;
}

signed main()
{
    fast;
    cin >> n >> q;
    vector<int> disc;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                modify(i, j, 1);
                arr[i][j] = 1;
            }
        }

    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            modify(x, y, (arr[x][y] ? -1 : 1));
            arr[x][y] ^= 1;
        }
        else
        {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) << '\n';
        }
    }
}
