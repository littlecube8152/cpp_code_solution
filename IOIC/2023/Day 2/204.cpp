#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q, t, s[500005], dis[500005];
pii io[500005];
vector<int> E[500005], sd[500005];
ll last;

void dfs(int u)
{
    io[u].F = ++t;
    for (int v : E[u])
    {
        dis[v] = dis[u] + 1;
        dfs(v);
    }
    sd[dis[u]].emplace_back(io[u].F);
    io[u].S = t;
}

struct segTree
{
    vector<ll> seg, lazy;
    int sz;

    void init(int _sz)
    {
        sz = _sz;
        seg = lazy = vector<ll>(4 * sz, 0);
    }

    ll getval(int i, ll L, ll R)
    {
        return seg[i] + lazy[i] * (R - L + 1);
    }

    void modify(int mL, int mR, ll val, int i = 1, int L = 0, int R = -1)
    {
        if (R == -1)
            R = sz - 1;

        if (mL <= L && R <= mR)
            lazy[i] += val;
        else if (mR < L || R < mL)
            return;
        else
        {
            int mid = (L + R) / 2;
            lazy[i << 1] += lazy[i];
            lazy[i << 1 | 1] += lazy[i];
            lazy[i] = 0;
            modify(mL, mR, val, i << 1, L, mid);
            modify(mL, mR, val, i << 1 | 1, mid + 1, R);
            seg[i] = getval(i << 1, L, mid) + getval(i << 1 | 1, mid + 1, R);
        }
    }

    ll query(int mL, int mR, int i = 1, int L = 0, int R = -1)
    {
        if (R == -1)
            R = sz - 1;

        if (mL <= L && R <= mR)
            return getval(i, L, R);
        else if (mR < L || R < mL)
            return 0;
        else
        {
            int mid = (L + R) / 2;
            lazy[i << 1] += lazy[i];
            lazy[i << 1 | 1] += lazy[i];
            seg[i] += lazy[i] * (R - L + 1);
            lazy[i] = 0;
            return query(mL, mR, i << 1, L, mid) +
                   query(mL, mR, i << 1 | 1, mid + 1, R);
        }
    }
} tree[500005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        E[p].emplace_back(i);
    }
    dfs(1);
    for (int i = 0; i < n; i++)
        tree[i].init(sd[i].size());

    for (int i = 1; i <= n; i++)
    {
        int j = lower_bound(sd[dis[i]].begin(), sd[dis[i]].end(), io[i].F) - sd[dis[i]].begin();
        tree[dis[i]].modify(j, j, s[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        ll a, b, c, u, v, w, x, y, z;
        cin >> u >> v >> w >> x >> y >> z;
        a = (u * (last % 1'000'000) + v) % 1'000'000;
        b = (w * (last % n) + x) % n;
        c = (y * (last % n) + z) % n + 1;
        int d = dis[c] + b;
        int l = lower_bound(sd[d].begin(), sd[d].end(), io[c].F) - sd[d].begin(),
            r = upper_bound(sd[d].begin(), sd[d].end(), io[c].S) - sd[d].begin() - 1;


        if(l > r)
        {
            last = 0;
            cout << "0\n";
            continue;
        }
        tree[d].modify(l, r, a);
        cout << (last = tree[d].query(l, r)) << '\n';
    }
}