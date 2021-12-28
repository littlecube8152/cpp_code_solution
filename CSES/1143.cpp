#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, seg[600005], x, arr[200005];

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
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
    }
}

int search(int l, int r, int i, int k)
{
    if (l == r)
        return l;
    else
    {
        int mid = (l + r) / 2;
        if (seg[i * 2] >= k)
            return search(l, mid, i * 2, k);
        else
            return search(mid + 1, r, i * 2 + 1, k);
    }
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        modify(1, n, 1, i, arr[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (seg[1] < x)
            cout << "0 ";
        else
        {
            int ans = search(1, n, 1, x);
            cout << ans << " ";
            arr[ans] -= x;
            modify(1, n, 1, ans, arr[ans]);
        }
    }
}