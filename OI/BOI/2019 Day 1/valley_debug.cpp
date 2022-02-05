#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll INF = 1e17;

int N, Sh, Q, E, head[20][100005], echild[20][100005], t[20], sz[100005], dfsorder[20][100005];
ll dis[20][100005], seg[20][400005];
pii io[20][100005];
bool hide[20][400005], isshop[100005], vis[100005];
vector<pair<int, pll>> edge[100005];

ll totsz;

inline void dfs_sz(int k, int &layer)
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

inline int dfs_find_cent(int k, int &layer, int &root)
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

inline void dfs_init(int k, int &layer, int &root)
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

inline void cent_dec(int root, int layer)
{
    dfs_sz(root, layer);
    int cent = dfs_find_cent(root, layer, root);
    dfs_init(cent, layer, cent);
    vis[cent] = 1;
    for (auto p : edge[cent])
        if (!vis[p.F])
            cent_dec(p.F, layer + 1);
}

inline void build(int &layer, int i = 1, int L = 1, int R = N)
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

inline ll getval(int layer, int i)
{
    if (hide[layer][i])
        return INF;
    else
        return seg[layer][i];
}

inline void modify(int &layer, int mL, int mR, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        hide[layer][i] ^= 1;
    else if (mR < L || R < mL)
        return;
    else
    {
        int mid = (L + R) / 2;
        if (mL <= mid)
            modify(layer, mL, mR, i * 2, L, mid);
        if (mR > mid)
            modify(layer, mL, mR, i * 2 + 1, mid + 1, R);
        seg[layer][i] = min(getval(layer, i * 2), getval(layer, i * 2 + 1));
    }
}

int k = 0;

inline ll query(int &layer, int qL, int qR, int i = 1, int L = 1, int R = N)
{
    k++;
    if (qL <= L && R <= qR)
        return getval(layer, i);
    else if (qR < L || R < qL)
        return INF;
    else
    {
        int mid = (L + R) / 2;
        return min((qL <= mid ? query(layer, qL, qR, i * 2, L, mid) : INF),
                   (qR > mid ? query(layer, qL, qR, i * 2 + 1, mid + 1, R) : INF));
    }
}
ll count_query(int layer, int qL, int qR, int i = 1, int L = 1, int R = N)
{
    k = 0;
    ll ans = query(layer, qL, qR, i, L, R);
    //cout << "query cost " << k << '\n';
    return ans;
}
signed main()
{

    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    E = N;
    time_t a = clock();
    assert(Q <= 100000);
    for (int i = 1; i < N; i++)
    {
        int A = i, B = i + 1, W = 1e9;
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
    cout << totsz << '\n';
    for (int i = 0; i < 20; i++)
        dis[i][E] = -INF;
    isshop[E] = 1;
    cout << (clock() - a) / 1.0 / CLOCKS_PER_SEC << '\n';
    for (int i = 0; i < 20; i++)
        build(i);
    cout << (clock() - a) / 1.0 / CLOCKS_PER_SEC << '\n';
    for (int i = 1; i <= Q; i++)
    {
        ll ans = INF, I = rand(), R = rand();
        //cin >> I >> R;
        for (int l = 0; l < 20; l++)
            if (head[l][R])
            {
                int snow = echild[l][I];

                if (!(io[l][snow].F <= io[l][R].F && io[l][R].S <= io[l][snow].S))
                {
                    if (io[l][head[l][R]].F <= io[l][snow].F && io[l][snow].S <= io[l][head[l][R]].S)
                        modify(l, io[l][snow].F, io[l][snow].S);
                    ans = min(ans, dis[l][R] + count_query(l, io[l][head[l][R]].F, io[l][head[l][R]].S));
                    if (io[l][head[l][R]].F <= io[l][snow].F && io[l][snow].S <= io[l][head[l][R]].S)
                        modify(l, io[l][snow].F, io[l][snow].S);

                    //cout << ans << " ";
                }
            }
            else
                break;
    }
    cout << (clock() - a) / 1.0 / CLOCKS_PER_SEC << '\n';
}