//#include "arithmetics.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, leafcnt, pre[200005], order[200005], seg[800005], root, head[200005], sz[200005], t, deg[200005], odx, dp[200005];
pii io[200005];
bool lazy[800005];
vector<int> E[200005];

int getval(int i, int L, int R)
{
    if (lazy[i])
        return (R - L + 1) - seg[i];
    else
        return seg[i];
}

void modify(int mL, int mR, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        lazy[i] ^= 1;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i * 2] ^= lazy[i];
        lazy[i * 2 + 1] ^= lazy[i];
        lazy[i] = 0;
        modify(mL, mR, i * 2, L, mid);
        modify(mL, mR, i * 2 + 1, mid + 1, R);
        seg[i] = getval(i * 2, L, mid) + getval(i * 2 + 1, mid + 1, R);
    }
}

int getans()
{
    return getval(1, 1, N);
}

void dfs(int k)
{
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            sz[k] += sz[i];
        }
    sz[k]++;
}

void ordering(int k, int h)
{
    io[k].F = ++t;
    order[k] = ++odx;
    head[k] = h;
    if (E[k].size() >= 1)
        ordering(E[k][0], h);
    else
        dp[k] = 1;
    for (int i = 1; i < E[k].size(); i++)
        ordering(E[k][i], E[k][i]);
    for (int i = 0; i < E[k].size(); i++)
        dp[k] ^= dp[E[k][i]];
    io[k].S = t;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        deg[i] = E[i].size();
        if (E[i].size() > 1)
            root = i;
        else
            leafcnt++;
    }
    dfs(root);
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 1; i <= N; i++)
        if (i != root)
            E[pre[i]].emplace_back(i);
    for (int i = 1; i <= N; i++)
        sort(E[i].begin(), E[i].end(), [&](int i1, int i2)
             { return sz[i1] > sz[i2]; });
    ordering(root, root);
    //for (int i = 1; i <= N; i++)
    //    cout << dp[i] << " \n"[i == N];
    //for (int i = 1; i <= N; i++)
    //    cout << order[i] << " \n"[i == N];
    //for (int i = 1; i <= N; i++)
    //    cout << head[i] << " \n"[i == N];
    for (int i = 1; i <= N; i++)
        if(dp[i])
            modify(order[i], order[i]);
    for (int i = 1; i <= Q; i++)
    {
        int D;
        vector<int> v;
        cin >> D;
        v.resize(D);
        for (int j = 0; j < D; j++)
            cin >> v[j];
        for (int j = 0; j < D; j++)
        {
            if(deg[v[j]] != 1)
            {
                int u = v[j];
                while(u != 0)
                {
                    modify(order[head[u]], order[u]);
                    u = pre[head[u]];
                }
                leafcnt++;
            }
            deg[v[j]]++;
        }
        //cout << "ans " << getans() << '\n';
        if(leafcnt % 2 == 0)
            cout << (N - 1) * 2  + D - getans() << '\n';
        else
            cout << "-1\n";
        for (int j = 0; j < D; j++)
        {
            deg[v[j]]--;
            if(deg[v[j]] != 1)
            {
                int u = v[j];
                while(u != 0)
                {
                    modify(order[head[u]], order[u]);
                    u = pre[head[u]];
                }
                leafcnt--;
            }
            
        }
    }
}
