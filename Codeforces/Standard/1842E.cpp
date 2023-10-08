/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, A, S, on[200005], dp[200005], seg[800005], lazy[800005];
vector<pii> in[200005], out[200005];

void init(int i = 1, int L = 0, int R = k)
{
    if (L == R)
        seg[i] = -A * L;
    else
    {
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
    }
}

void modify(int mL, int mR, ll val, int i = 1, int L = 0, int R = k)
{
    if (mL <= L && R <= mR)
    {
        seg[i] += val;
        lazy[i] += val;
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        seg[i << 1] += lazy[i];
        seg[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
    }
}

ll query(int mL, int mR, int i = 1, int L = 0, int R = k)
{
    if (mL <= L && R <= mR)
        return seg[i];
    else if (R < mL || mR < L)
        return 1e18;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        seg[i << 1] += lazy[i];
        seg[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        return min(query(mL, mR, i << 1, L, mid),
                   query(mL, mR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    fast;
    cin >> n >> k >> A;
    init();
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        in[y].emplace_back(pii(x, c));
        out[k - x].emplace_back(pii(y, c));
        on[y] += c;
    }
    for (int i = 0; i <= k; i++)
    {
        for (auto [x, c] : in[i])
            modify(0, i, c);
        for (auto [y, c] : out[i])
            modify(0, y, -c);
        dp[i] = min((i > 0 ? dp[i - 1] : 0) + on[i],
                    query(0, i - 1) + A * i);
        modify(i, i, (i > 0 ? dp[i - 1] : 0));
        // cerr << dp[i] << '\n';
    }
    cout << dp[k] << '\n';
}
