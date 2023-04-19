#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, t, child[100005], pre[100005][20], S[100005], T[100005], L[100005];
ll X[100005], Y[100005];
pii io[100005], range[100005];
vector<pii> E[100005];
pll check[100005];

struct BIT
{
    ll bit[100005];
    void init()
    {
        for (int i = 0; i <= N; i++)
            bit[i] = 0;
    }
    void modify(int pos, ll val)
    {
        assert(pos != 0);
        for (; pos <= N; pos += (pos & -pos))
            bit[pos] += val;
    }
    ll query(int pos)
    {
        ll ans = 0;
        for (; pos > 0; pos -= (pos & -pos))
            ans += bit[pos];
        return ans;
    }
} bit;

bool ischild(int r, int c)
{
    if (io[r].F <= io[c].F && io[c].S <= io[r].S)
        return 1;
    return 0;
}

int lca(int u, int v)
{
    int l = u;
    for (int p = 19; p >= 0; p--)
        if (pre[l][p] && !ischild(pre[l][p], v))
            l = pre[l][p];
    if (!ischild(l, v))
        l = pre[l][0];
    return l;
}

void dfs(int u)
{
    io[u].F = ++t;
    for (auto [v, i] : E[u])
        if (v != pre[u][0])
        {
            child[i] = v;
            pre[v][0] = u;
            for (int p = 1; p < 20; p++)
                pre[v][p] = pre[pre[v][p - 1]][p - 1];
            dfs(v);
        }
    io[u].S = t;
}

signed main()
{
    cin >> N >> M >> Q;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii(v, i));
        E[v].emplace_back(pii(u, i));
    }
    for (int i = 1; i <= M; i++)
        cin >> check[i].S >> check[i].F;
    sort(check + 1, check + 1 + M);
    dfs(1);
    //cerr << "dfs\n";
    vector<pii> query, nxt;
    for (int i = 1; i <= Q; i++)
    {
        cin >> S[i] >> T[i] >> X[i] >> Y[i];
        L[i] = lca(S[i], T[i]);
        range[i] = pii(0, M);
        query.emplace_back(pii(i, (range[i].F + range[i].S + 1) / 2));
    }
    //cerr << "lca\n";
    int iter = 20;
    while (iter--)
    {
        int qdx = 0;
        bit.init();
        for (int i = 0; i <= M; i++)
        {
            vector<pii> suc, fail;
            if (i)
            {
                bit.modify(io[child[check[i].S]].F, check[i].F);
                bit.modify(io[child[check[i].S]].S + 1, -check[i].F);
            }
            while (qdx < query.size() && query[qdx].S == i)
            {
                int j = query[qdx].F;
                if (bit.query(io[S[j]].F) + bit.query(io[T[j]].F) - 2 * bit.query(io[L[j]].F) <= Y[j])
                {
                    range[j].F = query[qdx].S;
                    suc.emplace_back(pii(j, (range[j].F + range[j].S + 1) / 2));
                }
                else
                {
                    range[j].S = query[qdx].S - 1;
                    fail.emplace_back(pii(j, (range[j].F + range[j].S + 1) / 2));
                }
                //cerr << j << ' ' << range[j].F << ' ' << range[j].S << ' ' << bit.query(io[S[j]].F) + bit.query(io[T[j]].F) - 2 * bit.query(io[L[j]].F) << '\n';
                qdx++;
            }
            for (auto p : fail)
                nxt.emplace_back(p);
            for (auto p : suc)
                nxt.emplace_back(p);
        }
        query.clear();
        query.swap(nxt);
        //cerr << "bs iter " << iter << '\n';
    }
    bit.init();
    int qdx = 0;
    for (int i = 1; i <= M; i++)
    {
        bit.modify(io[child[check[i].S]].F, -1);
        bit.modify(io[child[check[i].S]].S + 1, 1);
    }
    for (int i = 0; i <= M; i++)
    {
        vector<pii> suc, fail;
        if (i)
        {
            bit.modify(io[child[check[i].S]].F, 1);
            bit.modify(io[child[check[i].S]].S + 1, -1);
        }
        while (qdx < query.size() && query[qdx].S == i)
        {
            int j = query[qdx].F;
            X[j] += bit.query(io[S[j]].F) + bit.query(io[T[j]].F) - 2 * bit.query(io[L[j]].F);
            qdx++;
        }
    }
    //cerr << "calc ans\n";
    for (int i = 1; i <= Q; i++)
    {
        //cout << range[i].F << ' ';
        cout << max(-1LL, X[i]) << '\n';
    }
}