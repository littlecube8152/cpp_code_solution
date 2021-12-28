#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k, arr[10005], dp[10005];

struct SegTree
{
    int L, R, val;
};

SegTree seg[40005];

int build(int l, int r, int id)
{
    if (l == r)
    {
        seg[id] = SegTree{l, r, arr[l]};
        return seg[id].val;
    }
    int mid = (l + r) / 2;
    seg[id] = SegTree{l, r, max(build(l, mid, id * 2), build(mid + 1, r, id * 2 + 1))};
    return seg[id].val;
}

int query(int l, int r, int id)
{
    if (seg[id].L == seg[id].R)
        return seg[id].val;
    if (l <= seg[id].L && seg[id].R <= r)
        return seg[id].val;
    int mid = (seg[id].L + seg[id].R) / 2;
    if (r <= mid)
        return query(l, r, id * 2);
    if (mid + 1 <= l)
        return query(l, r, id * 2 + 1);
    return max(query(l, r, id * 2), query(l, r, id * 2 + 1));
}

signed main()
{
    ifstream cin;
    cin.open("teamwork.in");
    ofstream cout;
    cout.open("teamwork.out");

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
        for (int j = max(0, i - k); j < i; j++)
            dp[i] = max(dp[i], dp[j] + query(j + 1, i, 1) * (i - j));
    cout << dp[n] << '\n';
}