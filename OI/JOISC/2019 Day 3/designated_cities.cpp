#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, sz[200005], pre[200005], vis[200005];
ll tot, sum, dp[200005], val[200005], ans[200005], sum1[200005];
vector<pair<int, pll>> E[200005];
vector<int> cur;
vector<pll> leaf;

void calcSz(int u)
{
    vis[u] = sz[u] = 1;
    cur.emplace_back(u);
    for (auto [v, p] : E[u])
        if (!vis[v])
        {
            pre[v] = u;
            calcSz(v);
            sz[u] += sz[v];
        }
}

void calcDP(int u, int r)
{
    vis[u] = 1;
    int mx = 0;
    for (auto [v, p] : E[u])
        if (!vis[v])
        {
            pre[v] = (r == 0 ? v : r);
            calcDP(v, (r == 0 ? v : r));
            val[dp[v]] += p.F;
            if (val[dp[v]] > val[mx])
                mx = dp[v];
        }
    dp[u] = (mx == 0 ? u : mx);
}

void centroid(int r)
{
    cur.clear();
    pre[r] = 0;
    calcSz(r);
    int c = 0;
    for (auto i : cur)
    {
        vis[i] = 0;
        bool b = (sz[r] - sz[i]) <= sz[r] / 2;
        for (auto [j, p] : E[i])
            if (j != pre[i] && !vis[j])
                b &= sz[j] <= sz[r] / 2;
        if (b)
            c = i;
    }
    // cerr << "centroid dec " << c << '\n';
    // for (auto i : cur)
    //     cout << i << ' ';
    // cout << '\n';
    tot = sum1[c];
    calcDP(c, 0);
    leaf.clear();
    for (auto i : cur)
    {
        vis[i] = 0;
        if (dp[i] == i)
        {
            leaf.emplace_back(pll(val[dp[i]], pre[i]));
            val[dp[i]] = 0;
        }
        pre[i] = 0;
        dp[i] = 0;
    }
    if (leaf.size() < 2)
        return;
    sort(leaf.begin(), leaf.end(), greater<>());
    bool f = 0;
    for (int i = 1; i < (int)leaf.size(); i++)
    {
        if (f)
            leaf[i - 1] = leaf[i];
        else if (leaf[i].S != leaf[0].S)
        {
            f = 1;
            tot += leaf[i].F;
        }
    }
    leaf.pop_back();
    for (int i = 0; i < (int)leaf.size(); i++)
    {
        tot += leaf[i].F;
        ans[i + 2] = max(ans[i + 2], tot);
    }
    
    vis[c] = 1;
    for (auto [i, p] : E[c])
        if (!vis[i])
            centroid(i);
}

void calc1(int u)
{
    dp[u] = 0;
    for (auto [v, p] : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            calc1(v);
            dp[u] += dp[v] + p.S;
        }
}

void calc1root(int u)
{
    ans[1] = max(ans[1], sum1[u] = dp[u]);
    for (auto [v, p] : E[u])
        if (v != pre[u])
        {
            dp[v] += dp[u] - dp[v] + p.F - p.S;
            calc1root(v);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    if(N == 2)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        sum += C + D;
        ans[1] = max(C, D);
        ans[2] = C + D;
        goto ono;
    }
    for (int i = 1; i < N; i++)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        sum += C + D;
        E[A].emplace_back(make_pair(B, pll(C, D)));
        E[B].emplace_back(make_pair(A, pll(D, C)));
    }
    calc1(1);
    calc1root(1);
    for (int i = 1; i <= N; i++)
        dp[i] = 0;
    centroid(1);
    for (int i = 1; i <= N; i++)
        ans[i] = max(ans[i], ans[i - 1]);
ono:
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int E;
        cin >> E;
        cout << sum - ans[E] << '\n';
    }
}


/*
10
1 2 1 1
2 3 1 1
3 4 1 1
4 5 1 1
5 6 1 1
6 7 1 1
7 8 1 1
8 9 1 1
9 10 1 1
4
1
2
3
4
*/