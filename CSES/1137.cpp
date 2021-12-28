#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x);
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, arr[200005], seg[600005], pre[200005], timer = 1;
pii t[200005];
vector<int> e[200005];

void dfs(int x)
{
    t[x].F = timer++;
    for (int i : e[x])
        if (pre[x] != i)
        {
            pre[i] = x;
            dfs(i);
        }

    t[x].S = timer - 1;
}

void modify(int l, int r, int i, int pos, int val)
{
    int mid = (l + r) / 2;
    if (l == r)
        seg[i] = val;
    else
    {
        if (pos <= mid)
            modify(l, mid, i * 2, pos, val);
        else
            modify(mid + 1, r, i * 2 + 1, pos, val);
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

int query(int l, int r, int i, int a, int b)
{
    int mid = (l + r) / 2;
    if (b < l || r < a)
        return 0;
    if (a <= l && r <= b)
        return seg[i];
    return query(l, mid, i * 2, a, b) + query(mid + 1, r, i * 2 + 1, a, b);
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        modify(1, n, 1, t[i].F, arr[i]);
    
    for (int i = 1; i <= q; i++)
    {
        int a, x, y;
        cin >> a;
        if (a == 1)
        {
            cin >> x >> y;
            modify(1, n, 1, t[x].F, y);
        }
        else    
        {
            cin >> x;
            cout << query(1, n, 1, t[x].F, t[x].S) << '\n';
        }
    }
}