/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int N, M, dsu[1000006], rk[1000006];
vector<pii> v[21];

int find(int k)
{
    return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    if (rk[x] <= rk[y])
    {
        rk[y] += rk[x];
        dsu[x] = y;
    }
    else
        merge(y, x);
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = i, rk[i] = 1;
    for (int i = 1; i <= M; i++)
    {
        int x, y, len, lg;
        cin >> len >> x >> y;
        lg = __lg(len);
        v[lg].emplace_back(pii{x, y});
        v[lg].emplace_back(pii{x + len - (1 << lg), y + len - (1 << lg)});
    }
    for (int i = 20; i >= 0; i--)
    {
        for (auto [x, y] : v[i])
        {
            int rx = find(x), ry = find(y);
            if (rx != ry)
                merge(rx, ry);
        }
        if (i > 0)
            for (int j = 1; j <= N; j++)
            {
                int x = j + (1 << (i - 1)), y = find(j) + (1 << (i - 1));
                if(x <= N && y <= N)
                v[i - 1].emplace_back(pii{x, y});
            }
    }
    int cnt = 0;
	
    ll ans = 1;
    for (int i = 1; i <= N; i++)
        if(find(i) == i)
            cnt++;
    for (int i = 1; i <= cnt; i++)
        ans = ans * 26 % MOD;
    cout << ans << '\n';
}
