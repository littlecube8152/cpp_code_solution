#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

int n, m, seg[5000005], ans;

vector<array<int, 3>> mod, qry;

void modify(int l, int r, int i, int p, int v)
{
    if (l == r)
        seg[i] = v;
    else
    {
        int mid = (l + r) / 2;
        if (p <= mid)
            modify(l, mid, i * 2, p, v);
        else
            modify(mid + 1, r, i * 2 + 1, p, v);
        seg[i] = (seg[i * 2] + seg[i * 2 + 1]);
    }
}

int query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return 0;
    int mid = (l + r) / 2;
    return query(l, mid, i * 2, a, b) + query(mid + 1, r, i * 2 + 1, a, b);
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000001, x2 += 1000001, y1 += 1000001, y2 += 1000001;
        if (x1 == x2)
        {
            mod.pb((array<int, 3>{y1, x1, 1}));
            mod.pb((array<int, 3>{y2 + 1, x1, 0}));
        }
        else
        {
            qry.pb((array<int, 3>{y1, x1, x2}));
        }
    }
    sort(mod.begin(), mod.end(), greater<array<int, 3>>());
    sort(qry.begin(), qry.end(), greater<array<int, 3>>());
    for (int i = 1; i <= 2000001; i++)
    {
        while (!mod.empty() && mod.back()[0] == i)
        {
            modify(1, 2000001, 1, mod.back()[1], mod.back()[2]);
            mod.pop_back();
        }
        while (!qry.empty() && qry.back()[0] == i)
        {
            ans += query(1, 2000001, 1, qry.back()[1], qry.back()[2]);
            qry.pop_back();
        }
    }
    cout << ans << '\n';
}