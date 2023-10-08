#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q, a[100005], ord[100005], bad[100005], ans[300005];
pii p[100005];
vector<int> imp[100005];
vector<pii> qs[100005];

pii seg[400005];

pii merge(pii p, pii q)
{
    if (p.F < q.F)
        return pii(p.F, min(p.S, q.F));
    return pii(q.F, min(p.F, q.S));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        pii ans = pii(2e9, 2e9);
        for (int j = l; j <= r; j++)
            for (int k = j + 1; k <= r; k++)
                ans = merge(ans, pii(abs(a[j] - a[k]), 2e9));
        cout << ans.S << '\n';
    }
}