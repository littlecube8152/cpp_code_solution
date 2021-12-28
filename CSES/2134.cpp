/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, q, pre[200005], t, order[200005], s[200005], head[200005], seg[800005], val[200005], odx = 0;
vector<int> E[200005];
pii io[200005];

void modify(int pos, ll val, int i = 1, int L = 1, int R = n)
{
    if (L == R)
        seg[i] = val;
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, val, i * 2, L, mid);
        else
            modify(pos, val, i * 2 + 1, mid + 1, R);
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
    }
}

int query(int qL, int qR, int i = 1, int L = 1, int R = n)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (R < qL || qR < L)
        return -1e9;
    else
    {
        int mid = (L + R) / 2;
        return max(query(qL, qR, i * 2, L, mid), query(qL, qR, i * 2 + 1, mid + 1, R));
    }
}

void dfs(int k)
{
    io[k].F = ++t;
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            s[k] += s[i];
        }
    s[k]++;
    io[k].S = t;
}

void ordering(int k, int r)
{
    order[k] = ++odx;
    head[k] = r;
    if (!E[k].empty())
        ordering(E[k].back(), r);
    for (int i = 0; i + 1 < E[k].size(); i++)
        ordering(E[k][i], E[k][i]);
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        sort(E[i].begin(), E[i].end(), [&](int i1, int i2)
             { return s[i1] < s[i2]; });
        if (i != 1)
            E[i].pop_back();
    }
    ordering(1, 1);
    for (int i = 1; i <= n; i++)
        modify(order[i], val[i]);
    for (int i = 1; i <= q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            modify(order[a], b);
        else
        {
            int ans = -1e9;
            while (head[a] != head[b])
                if (io[head[a]].F <= io[head[b]].F && io[head[b]].S <= io[head[a]].S)
                {
                    ans = max(ans, query(order[head[b]], order[b]));
                    //cout << "query " << b << " " << head[b] << '\n';
                    b = pre[head[b]];
                }
                else
                {
                    ans = max(ans, query(order[head[a]], order[a]));
                    //cout << "query " << a << " " << head[a] << '\n';
                    a = pre[head[a]];
                }
            ans = max(ans, query(min(order[a], order[b]), max(order[a], order[b])));
            cout << ans << ' ';
        }
    }
}

/*
5 25
2 4 1 3 3
1 2
1 3
2 4
2 5

2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 2 1
2 2 2
2 2 3
2 2 4
2 2 5
2 3 1
2 3 2
2 3 3
2 3 4
2 3 5
2 4 1
2 4 2
2 4 3
2 4 4
2 4 5
2 5 1
2 5 2
2 5 3
2 5 4
2 5 5
*/