#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll INF = 1e17;

ll N, Sh, Q, E, head[20][100005], dis[20][100005], seg[20][400005], echild[20][100005], t[20], vis[100005], sz[100005], dfsorder[20][100005];
pii io[20][100005];
bool isshop[100005], hide[20][400005];
vector<pair<int, pll>> edge[100005];

void dfs_sz(int k, int layer)
{
    vis[k] = 1;
    sz[k] = 1;
    for (auto p : edge[k])
        if (!vis[p.F])
        {
            dfs_sz(p.F, layer);
            sz[k] += sz[p.F];
        }
    vis[k] = 0;
}

int dfs_find_cent(int k, int layer, int root)
{
    vis[k] = 1;
    bool valid = true;
    for (auto p : edge[k])
        if (!vis[p.F])
        {
            int cent = dfs_find_cent(p.F, layer, root);
            if (cent)
            {
                vis[k] = 0;
                return cent;
            }
            if (sz[p.F] > sz[root] / 2)
                valid = false;
        }
    vis[k] = 0;
    if (valid && sz[root] - sz[k] <= sz[root] / 2)
        return k;
    return 0;
}

void dfs_init(int k, int layer, int root)
{
    vis[k] = 1;

    io[layer][k].F = ++t[layer];
    dfsorder[layer][io[layer][k].F] = k;
    head[layer][k] = root;
    for (auto p : edge[k])
        if (!vis[p.F])
        {
            dis[layer][p.F] = dis[layer][k] + p.S.S;
            echild[layer][p.S.F] = p.F;
            dfs_init(p.F, layer, root);
        }
    vis[k] = 0;
    io[layer][k].S = t[layer];
}

void cent_dec(int root, int layer)
{
    assert(layer <= 18);
    dfs_sz(root, layer);
    int cent = dfs_find_cent(root, layer, root);
    dfs_init(cent, layer, cent);
    vis[cent] = 1;
    for (auto p : edge[cent])
        if (!vis[p.F])
            cent_dec(p.F, layer + 1);
}

void build(int layer, int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        int u = dfsorder[layer][L];
        if (isshop[u])
            seg[layer][i] = dis[layer][u];
        else
            seg[layer][i] = INF;
    }
    else
    {
        int mid = (L + R) / 2;
        build(layer, i * 2, L, mid);
        build(layer, i * 2 + 1, mid + 1, R);
        seg[layer][i] = min(seg[layer][i * 2], seg[layer][i * 2 + 1]);
    }
}

ll getval(int layer, int i)
{
    if (hide[layer][i])
        return INF;
    else
        return seg[layer][i];
}

void modify(int layer, int mL, int mR, bool val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        hide[layer][i] = val;
    else if (mR < L || R < mL)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify(layer, mL, mR, val, i * 2,         L, mid);
        modify(layer, mL, mR, val, i * 2 + 1, mid + 1, R);
        seg[layer][i] = min(getval(layer, i * 2), getval(layer, i * 2 + 1));
    }
}

ll query(int layer, int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return getval(layer, i);
    else if (qR < L || R < qL)
        return INF;
    else
    {
        int mid = (L + R) / 2;
        return min(query(layer, qL, qR, i * 2, L, mid),
                   query(layer, qL, qR, i * 2 + 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Sh >> Q >> E;
    assert(Q <= 100000);
    for (int i = 1; i < N; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;
        edge[A].emplace_back(make_pair(B, pll{i, W}));
        edge[B].emplace_back(make_pair(A, pll{i, W}));
    }
    for (int i = 1; i <= Sh; i++)
    {
        int u;
        cin >> u;
        isshop[u] = 1;
    }
    cent_dec(1, 0);
    for (int i = 0; i < 20; i++)
        dis[i][E] = -INF;
    isshop[E] = 1;
    for (int i = 0; i < 20; i++)
        build(i);
    for (int i = 1; i <= Q; i++)
    {
        ll ans = INF, I, R;
        cin >> I >> R;
        for (int l = 0; l < 20; l++)
            if (head[l][R])
            {
                int snow = echild[l][I];

                if (!(io[l][snow].F <= io[l][R].F && io[l][R].S <= io[l][snow].S))
                {
                    modify(l, io[l][snow].F, io[l][snow].S, 1);
                    ans = min(ans, dis[l][R] + query(l, io[l][head[l][R]].F, io[l][head[l][R]].S));
                    modify(l, io[l][snow].F, io[l][snow].S, 0);

                    //cout << ans << " ";
                }
            }
        if (ans < 0)
            cout << "escaped\n";
        else if (ans >= 1e15)
            cout << "oo\n";
        else
            cout << ans << '\n';
    }
}