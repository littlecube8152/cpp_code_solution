#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, L, R, K, a[100005], b[100005], c[100005], d[100005], w[100005], dp[100005], vis[100005], sz[100005], cen[100005][20];
vector<pii> E[100005];
vector<pii> tree[100005], seg[100005];

void dfs(int u)
{
    vis[u] = sz[u] = 1;
    for (auto [v, _] : E[u])
        if (!vis[v])
            dfs(v), sz[u] += sz[v];
    vis[u] = 0;
}

void dfscalc(int u, int r)
{
    vis[u] = 1;
    if (tree[r].size() <= d[u])
        tree[r].emplace_back(pii(-1e9, 0));

    tree[r][d[u]] = max(tree[r][d[u]], pii(dp[u], u));

    for (auto [v, w] : E[u])
        if (!vis[v])
            d[v] = d[u] + 1, dp[v] = dp[u] + w, dfscalc(v, r);

    vis[u] = 0;
}

pii sol;

void csep(int r, int l = 0)
{
    dfs(r);
    int c = r;
    while (true)
    {
        int f = 0;
        for (auto [u, _] : E[c])
            if (!vis[u] && sz[u] < sz[c] && sz[u] >= (sz[r] + 1) / 2)
                f = u;
        if (f)
            c = f;
        else
            break;
    }
    cen[r][l] = c;
    vis[c] = 1;
    for (auto [u, w] : E[c])
        if (!vis[u])
            csep(u, l + 1);
}

void cdec(int r, int l = 0)
{
    int c = cen[r][l];

    // cerr << "cdec " << c << '\n';

    vis[c] = 1;
    vector<int> ch;
    for (auto [u, w] : E[c])
        if (!vis[u])
        {
            d[u] = 1;
            dp[u] = w;
            ch.emplace_back(u);
            tree[u].emplace_back(pii(0, c));
            dfscalc(u, u);
        }

    sort(ch.begin(), ch.end(), [&](int i, int j)
         { return tree[i].size() > tree[j].size(); });

    int M = ch.size();
    if (M == 0)
        return;

    for (int k = 0; k < M; k++)
    {
        int u = ch[k];
        deque<pair<pii, int>> dq;
        int P = tree[u].size();

        seg[u].resize(P);
        for (int i = 0, j = 0; i < P; i++)
        {
            while (j <= i + K && j < P)
            {
                while (!dq.empty() && dq.back().F <= tree[u][j])
                    dq.pop_back();
                dq.push_back(pair<pii, int>(tree[u][j], j));
                j++;
            }
            seg[u][i] = dq.front().F;
            if (dq.front().S == i)
                dq.pop_front();
        }
    }
    int v = ch[0];
    for (int i = 1; i < tree[v].size(); i++)
        tree[v][i] = max(tree[v][i], tree[v][i - 1]);
    for (int k = 1; k < M; k++)
    {
        int u = ch[k];
        int P = tree[u].size();

        for (int i = 0; i < P && i <= L; i++)
        {
            int j = L - i;
            if (j >= tree[v].size())
                continue;
            if (tree[u][i].F + seg[v][j].F >= 0)
                sol = pii(tree[u][i].S, seg[v][j].S);
        }
        for (int i = L + 1; i < P && i <= R; i++)
        {
            int j = R - i;
            j = min(j, (int)tree[v].size() - 1);

            if (tree[u][i].F + tree[v][j].F >= 0)
                sol = pii(tree[u][i].S, tree[v][j].S);
        }

        for (int i = 0; i < P; i++)
            seg[v][i] = max(seg[u][i], seg[v][i]);
        for (int i = 1; i < P; i++)
            tree[u][i] = max(tree[u][i], tree[u][i - 1]);
        for (int i = 0; i < P; i++)
            tree[v][i] = max(tree[u][i], tree[v][i]);
    }
    for (int k = 0; k < M; k++)
    {
        int u = ch[k];
        tree[u].clear();
        seg[u].clear();
    }

    for (auto [u, w] : E[c])
        if (!vis[u])
            cdec(u, l + 1);
}

bool check(int m)
{
    // cerr << "search " << m << '\n';
    
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 1; i < N; i++)
    {
        E[a[i]].emplace_back(pii(b[i], (c[i] >= m ? 1 : -1)));
        E[b[i]].emplace_back(pii(a[i], (c[i] >= m ? 1 : -1)));
    }
    sol = pii(-1, -1);
    cdec(1);
    for (int i = 1; i <= N; i++)
        vis[i] = 0;

    return sol != pii(-1, -1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L >> R;
    if (N == 2)
    {
        cout << 1 << ' ' << 2 << '\n';
        return 0;
    }

    K = R - L;

    for (int i = 1; i < N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        w[i] = i;
    }

    sort(w + 1, w + N, [&](int i, int j)
         { return c[i] < c[j]; });

    for (int i = 1; i < N; i++)
    {
        int tmp = c[w[i]];
        c[w[i]] = i;
        w[i] = tmp;
    }

    for (int i = 1; i < N; i++)
    {
        E[a[i]].emplace_back(pii(b[i], 0));
        E[b[i]].emplace_back(pii(a[i], 0));
    }
    csep(1);
    fill(vis + 1, vis + 1 + N, 0);

    int l = 1, r = N - 1;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    check(l);
    cout << sol.F << ' ' << sol.S << '\n';
}