#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int C = 1000000;
ll N, ans, seg[4000005], lazy[4000005];

void modify(int mL, int mR, int val, int i = 1, int L = 0, int R = C)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R <= mL || mR <= L)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid, R);
    }
    if(lazy[i])
        seg[i] = R - L;
    else
        seg[i] = (R - L == 1 ? 0 : seg[i << 1] + seg[i << 1 | 1]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    vector<tuple<int, int, int, int>> v;
    for (int i = 1; i <= N; i++)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        v.emplace_back(make_tuple(d, l, r, 1));
        v.emplace_back(make_tuple(u, l, r, -1));
    }
    sort(v.begin(), v.end());
    int prev = 0;
    for (auto [y, x1, x2, val] : v)
    {
        if(y != prev)
        {
            ans += (y - prev) * seg[1];
            prev = y;
        }
        modify(x1, x2, val);
    }
    cout << ans << '\n';
}