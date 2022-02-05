#pragma GCC optimize("O3,unroll-loops")
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

int arr[(1 << 17) + 5], n, m, seg[(1 << 19) + 5];

void modify(int l, int r, int i, int p, int v)
{
    if (l == r)
        seg[i] = v;
    else
    {
        int mid = (l + r) / 2;
        if(p <= mid)
            modify(l, mid, i * 2, p, v);
        else
            modify(mid + 1, r, i * 2 + 1, p, v);
        if((int)log2(r - l + 1) % 2)
            seg[i] = seg[i * 2] | seg[i * 2 + 1];
        else 
            seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
    } 
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= (1 << n);i++)
    {
        int x;
        cin >> x;
        modify(1, (1 << n), 1, i, x);

    }
    for (int i = 1; i <= m;i++)
    {
        int p, x;
        cin >> p >> x;
        modify(1, (1 << n), 1, p, x);
        cout << seg[1] << '\n';
    }
}