#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q, a[100005], ord[100005], ans[3000005];
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

void init()
{
    for (int i = 0; i <= 4 * n; i++)
        seg[i] = pii(2e9, 2e9);
}

void force(int pos, int val, int i = 1, int L = 1, int R = n)
{
    if (L == R)
        seg[i] = pii(val, 2e9);
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            force(pos, val, i << 1, L, mid);
        else
            force(pos, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

void modify(int pos, int val, int i = 1, int L = 1, int R = n)
{
    if (L == R)
        seg[i] = merge(seg[i], pii(val, 2e9));
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, val, i << 1, L, mid);
        else
            modify(pos, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

pii query(int qL, int qR, int i = 1, int L = 1, int R = n)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (qR < L || R < qL)
        return pii(2e9, 2e9);
    else
    {
        int mid = (L + R) / 2;
        return merge(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

int findf(int v)
{
    return lower_bound(p + 1, p + 1 + n, pii(v, n + 1)) - p - 1;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int t = 0; t <= 1; t++)
    {
        for (int i = 1; i <= n; i++)
            p[i] = pii(a[i], -i);
        sort(p + 1, p + 1 + n);
        for (int i = 1; i <= n; i++)
            ord[-p[i].S] = i;
        // find first
        init();
        for (int i = 1; i <= n; i++)
        {
            int c = 2e9;
            bool flag = 1;
            while (flag)
            {
                assert(imp[i].size() <= 400);
                if (c == 0)
                    flag = 0;
                int v = findf(a[i] + c / 2);
                if (v < ord[i])
                    break;
                int x = -query(ord[i], v).F;
                if (x > 0)
                {
                    imp[i].emplace_back(x);
                    // update c
                    c = abs(a[i] - a[x]);
                }
                else
                    break;
            }
            modify(ord[i], -i);
        }
        // find second
        init();
        for (int i = 1; i <= n; i++)
        {
            int c = 2e9;
            bool flag = 1;
            vector<int> ban = imp[i];
            for (int j : ban)
                if(j < i)
                    force(ord[j], 2e9);
            while (flag)
            {
                if (c == 0)
                    flag = 0;
                int v = findf(a[i] + c / 2);
                if (v < ord[i])
                    break;
                int x = -query(ord[i], v).F;
                if (x > 0)
                {
                    imp[i].emplace_back(x);
                    // update c
                    c = abs(a[i] - a[x]);
                }
                else
                    break;
            }
            for (int j : ban)
                if(j < i)
                    modify(ord[j], -j);
            modify(ord[i], -i);
        }
        for (int i = 1; i <= n; i++)
            a[i] = -a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sort(imp[i].begin(), imp[i].end());
        imp[i].resize(unique(imp[i].begin(), imp[i].end()) - imp[i].begin());
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        qs[r].emplace_back(pii(l, i));
    }

    init();
    for (int r = 1; r <= n; r++)
    {
        for (auto l : imp[r])
            modify(l, abs(a[r] - a[l]));
        for (auto [l, i] : qs[r])
            ans[i] = query(l, r).S;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}