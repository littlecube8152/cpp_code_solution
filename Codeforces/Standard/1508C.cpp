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

int n, m, deg[200005], dsu[200005], size[200005], adj[800][800];
set<pair<int, pii>> e;
vector<pair<int, pii>> e2;
map<pii, int> mp;

time_t T = clock();

void init()
{
    for (int i = 1; i <= n; i++)
        dsu[i] = i, size[i] = 1;
}

int find(int k)
{
    return k == dsu[k] ? k : k = find(dsu[k]);
}

bool Union(int x, int y)
{
    if (x == y)
        return 0;
    if (size[x] < size[y])
        dsu[x] = y, size[y] += size[x];
    else
        dsu[y] = x, size[x] += size[y];
    return 1;
}

int MST()
{
    int ans = 0, cnt = 0;
    for (auto i : e)
    {
        int rx = find(i.S.F), ry = find(i.S.S);
        if (rx != ry)
        {
            Union(rx, ry);
            ans += i.F, cnt++;
        }
        if (cnt == n)
            break;
    }
    return ans;
}

signed main()
{
    fast;
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        deg[x]++, deg[y]++;
        e.insert(make_pair(w, make_pair(min(x, y), max(x, y))));
    }

    if (n * (n - 1) / 2 - m >= n)
    {
        int pre = 0;
        int ans = 0, cnt = 1;
        for (int i = 1; i <= n; i++)
            if (deg[i] < n - 1)
            {
                if (pre != 0)
                    if (Union(find(i), find(pre)))
                        cnt++;
                pre = i;
            }

        for (auto i : e)
        {
            int rx = find(i.S.F), ry = find(i.S.S);
            if (Union(rx, ry))
                ans += i.F, cnt++;
        }
        assert(cnt == n);
        cout << ans;
    }
    else
    {
        int XOR = 0, mx = 0;
        for (auto i : e)
        {
            adj[i.S.F][i.S.S] = 1;
            XOR ^= i.F;
            mx = max(mx, i.F);
        }
        //if ((n * (n - 1) / 2) % 2)
        //    XOR ^= ((1LL << (__lg(mx) + 1)) - 1);
        int res = 1000000000000000;
        vector<pii> v;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                if (!adj[i][j])
                    v.pb(make_pair(i, j));
            }

        for (auto p : v)
        {
            if (clock() - T > 2.8 * CLOCKS_PER_SEC)
                break;
            e.insert(make_pair(XOR, p));
            init();
            for (auto q : v)
                if (p != q)
                    Union(find(q.F), find(q.S));
            res = min(res, MST());
            e.insert(make_pair(0, p));
        }

        cout << res;
    }
}
