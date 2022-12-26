#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, k, seg[800005], lazy[800005], ans, used[200005];
pll p[200005];
vector<ll> x;
vector<pll> y;

void modify(int mL, int mR, int val, int i = 1, int L = 0, int R = 2 * N)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        seg[i] += lazy[i];

        lazy[i + 1] += lazy[i];
        lazy[i + (mid - L + 1) * 2] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + (mid - L + 1) * 2, mid + 1, R);
        seg[i] = max(seg[i + 1] + lazy[i + 1], seg[i + (mid - L + 1) * 2] + lazy[i + (mid - L + 1) * 2]);
    }
}

signed main()
{
    cin >> N >> k;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].F >> p[i].S;
        p[i] = pll{p[i].F - p[i].S, p[i].F + p[i].S};
        x.emplace_back(p[i].F - k);
        x.emplace_back(p[i].F + k);
        y.emplace_back(pll{p[i].S - k, -i});
        y.emplace_back(pll{p[i].S + k, i});
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(y.begin(), y.end());
    for (auto [_, id] : y)
    {
        id = abs(id);
        int L = lower_bound(x.begin(), x.end(), p[id].F - k) - x.begin();
        int R = lower_bound(x.begin(), x.end(), p[id].F + k) - x.begin();
        modify(L, R, (used[id] ? -1 : 1));
        ans = max(ans, seg[1] + lazy[1]);
        used[id] = 1;
    }
    cout << ans << '\n';
}
