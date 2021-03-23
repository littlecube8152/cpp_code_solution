#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x);
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, dis[200005];
pii seg[1200005], t[200005];
vector<int> e[200005];
vector<pii> arr = {pii{0, 0}};

void dfs(int k)
{
    t[k].F = arr.size();
    arr.pb(make_pair(dis[k], k));
    for (int i : e[k])
    {
        dis[i] = dis[k] + 1;
        dfs(i);
        arr.pb(make_pair(dis[k], k));
    }
    t[k].S = arr.size() - 1;
}

void modify(int l, int r, int i, int pos, pii val)
{
    if (l == r)
        seg[i] = val;
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
            modify(l, mid, i * 2, pos, val);
        else
            modify(mid + 1, r, i * 2 + 1, pos, val);
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

pii query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return pii{100000000, 0};
    int mid = (l + r) / 2;
    return min(query(l, mid, i * 2, a, b), query(mid + 1, r, i * 2 + 1, a, b));
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[x].pb(i);
    }
    dfs(1);
    for (int i = 1; i < arr.size(); i++)
        modify(1, arr.size() - 1, 1, i, arr[i]);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << query(1, arr.size() - 1, 1, min(t[x].F, t[y].F), max(t[x].S, t[y].S)).S << '\n';
    }
}