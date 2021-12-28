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
ll arr[200005], seg[800005], lazy[800005], ans[200005], qdx = 0;
vector<pair<pii, int>> queries;
vector<pll> mono;

void modify(ll ml, ll mr, ll val, ll i = 1, ll l = 1, ll r = n)
{
    if (mr < l || r < ml)
        return;
    if (ml <= l && r <= mr)
    {
        lazy[i] += val;
        return;
    }
    ll mid = (l + r) / 2;
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
    modify(ml, mr, val, i * 2, l, mid);
    modify(ml, mr, val, i * 2 + 1, mid + 1, r);
    seg[i] = seg[i * 2] + lazy[i * 2] * (mid - l + 1) + seg[i * 2 + 1] + lazy[i * 2 + 1] * (r - mid);
}

ll query(ll ql, ll qr, ll i = 1, ll l = 1, ll r = n)
{
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return seg[i] + lazy[i] * (r - l + 1);
    ll mid = (l + r) / 2;
    seg[i] += lazy[i] * (r - l + 1);
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
    return query(ql, qr, i * 2, l, mid) + query(ql, qr, i * 2 + 1, mid + 1, r);
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        arr[i] = arr[i + 1] - arr[i];
    arr[n] = 0;
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries.emplace_back(pair<pii, int>{{a, b}, i});
    }

    sort(queries.begin(), queries.end());
    qdx = queries.size() - 1;
    mono.emplace_back(pll{n, 1e17});
    for (int i = n; i >= 1; i--)
    {

        while (!mono.empty() && arr[i] + mono.back().S <= 0)
        {
            modify(i + 1, mono.back().F, mono.back().S);
            arr[i] += mono.back().S;
            mono.pop_back();
        }
        if (arr[i] < 0)
        {
            modify(i + 1, mono.back().F, -arr[i]);
            mono.back().S += arr[i];
        }
        else if (arr[i] > 0)
            mono.emplace_back(pll{i, arr[i]});
        while (qdx >= 0 && queries[qdx].F.F == i)
        {
            ans[queries[qdx].S] = query(i, queries[qdx].F.S);
            qdx--;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}
