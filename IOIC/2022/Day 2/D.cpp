#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, fourN;
// (a, b) = (i, i + N);
int a[20004], order[20004], sorted[20004], leaf[20004], vis[80005], scc[80005];
// segment tree => 2N * 2 = 4N nodes
// (+, -) = (i, i + 4 * N); => 8N nodes
vector<int> E[80005], rE[80005], rev;
auto ordering = [](int i, int j)
{ return a[i] < a[j]; };

// find the leaf and build the edge [L, R]+ -> [L, mid][mid + 1, R]+, [L, R]- -> [L, mid][mid + 1, R]-
void build(int i = 1, int L = 1, int R = 2 * N)
{
    if (L != R)
    {
        int mid = (L + R) / 2;
        E[i + 1].emplace_back(i);
        E[i + 2 * (mid - L + 1)].emplace_back(i);
        E[i + fourN].emplace_back(i + 1 + fourN);
        E[i + fourN].emplace_back(i + 2 * (mid - L + 1) + fourN);
        build(i + 1, L, mid);
        build(i + 2 * (mid - L + 1), mid + 1, R);
    }
    else
        leaf[order[L]] = i;
}

// add the edge u+ -> [mL, mR]- and [mL, mR]+ -> u-
void modify(int u, int mL, int mR, int i = 1, int L = 1, int R = 2 * N)
{
    if (mR < mL)
        return;
    if (mL <= L && R <= mR)
    {
        E[u].emplace_back(i + fourN);
        E[i].emplace_back(u + fourN);
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify(u, mL, mR, i + 1, L, mid);
        modify(u, mL, mR, i + 2 * (mid - L + 1), mid + 1, R);
    }
}

void dfs(int k)
{
    for (int i : E[k])
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    rev.push_back(k);
}

void dfs2(int k, int idx)
{
    for (int i : rE[k])
        if (vis[i] != 2)
        {
            vis[i] = 2;
            dfs2(i, idx);
        }
    scc[k] = idx;
}

ll bs(ll L, ll R)
{
    if (L == R)
        return L;
    int mid = (L + R + 1) / 2;
    build();
    for (int i = 1; i <= 2 * N; i++)
    {
        int ldx = upper_bound(sorted + 1, sorted + 1 + 2 * N, a[order[i]] - mid) - sorted;
        int rdx = lower_bound(sorted + 1, sorted + 1 + 2 * N, a[order[i]] + mid) - sorted - 1;
        modify(leaf[order[i]], ldx, i - 1);
        modify(leaf[order[i]], i + 1, rdx);
    }
    for (int i = 1; i <= N; i++)
    {
        E[leaf[i] + fourN].emplace_back(leaf[i + N]);
        E[leaf[i + N] + fourN].emplace_back(leaf[i]);
    }
    for (int i = 1; i <= 8 * N; i++)
        for (int j : E[i])
            rE[j].emplace_back(i);
    for (int i = 1; i <= 8 * N; i++)
        if (!vis[i])
            dfs(i);
    reverse(rev.begin(), rev.end());
    for (int i : rev)
        if (vis[i] != 2)
            dfs2(i, i);
    bool valid = true;
    for (int i = 1; i <= 2 * N; i++)
        if (scc[leaf[i]] == scc[leaf[i] + fourN])
            valid = false;
    for (int i = 1; i <= 8 * N; i++)
    {
        vis[i] = scc[i] = 0;
        E[i].clear();
        rE[i].clear();
    }
    rev.clear();
    if (valid)
        return bs(mid, R);
    else
        return bs(L, mid - 1);
}

int main()
{
    cin >> N;
    fourN = N * 4;
    if (N == 1)
    {
        cout << 1000000000 << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
        cin >> a[i] >> a[i + N];
    for (int i = 1; i <= 2 * N; i++)
        order[i] = i;
    sort(order + 1, order + 1 + 2 * N, ordering);
    for (int i = 1; i <= 2 * N; i++)
        sorted[i] = a[order[i]];
    cout << bs(0, ceil(1e9 / (N - 1.0))) << '\n';
}