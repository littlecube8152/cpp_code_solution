#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, Q, in[100005], out[100005], child[100005], t, pre[100005];
ll w, lazy[800005], edge[100005];
vector<pii> E[100005];

struct node
{
    ll a, b, c, ab, bc, abc;
} seg[800005];

node merge(node L, node R)
{
    return node{max(L.a, R.a),
                max(L.b, R.b),
                max(L.c, R.c),
                max({L.ab, R.ab, L.a + R.b}),
                max({L.bc, R.bc, L.b + R.c}),
                max({L.abc, R.abc, L.ab + R.c, L.a + R.bc})};
}

void apply(int i, ll tag)
{
    lazy[i] += tag;
    seg[i] = node{seg[i].a + tag, seg[i].b - 2 * tag, seg[i].c + tag, seg[i].ab - tag, seg[i].bc - tag, seg[i].abc};
}

void modify(int mL, int mR, ll val, int i = 1, int L = 1, int R = 2 * N)
{
    if (mL <= L && R <= mR)
        apply(i, val);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        apply(i << 1, lazy[i]);
        apply(i << 1 | 1, lazy[i]);
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

void dfs(int u)
{
    in[u] = ++t;
    out[u] = t;
    for (auto [v, i] : E[u])
        if (pre[u] != v)
        {
            pre[v] = u;
            child[i] = v;
            dfs(v);
            out[u] = ++t;
        }
}

signed main()
{
    cin >> N >> Q >> w;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v >> edge[i];
        E[u].emplace_back(pii(v, i));
        E[v].emplace_back(pii(u, i));
    }
    dfs(1);
    for (int i = 1; i < N; i++)
        modify(in[child[i]], out[child[i]], edge[i]);
    ll last = 0;
    for (int i = 1; i <= Q; i++)
    {
        ll d, e;
        cin >> d >> e;
        d = (d + last) % (N - 1) + 1;
        e = (e + last) % w;
        modify(in[child[d]], out[child[d]], e - edge[d]);
        edge[d] = e;
        cout << (last = seg[1].abc) << '\n';
    }
}
