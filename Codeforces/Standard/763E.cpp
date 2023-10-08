/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct node
{
    // length at most 10
    vector<int> v;
    int front(int i = 0)
    {
        return v[i];
    }
    int back(int i = 0)
    {
        return v[(int)v.size() - i - 1];
    }
    bool empty()
    {
        return v.empty();
    }
    int l, r, edge;
} seg[400005];

vector<int> E[100005];

node merge(node p, node q)
{
    if (p.empty())
        return q;
    if (q.empty())
        return p;
    int edge = p.edge + q.edge;
    for (int i = max(p.l, p.r - 4); i <= p.r; i++)
        for (auto j : E[i])
            if (q.l <= j && j <= min(q.l + 4, q.r))
            {
                int a = p.back(p.r - i), b = q.front(j - q.l);
                if (a == b)
                    continue;
                for (auto &k : p.v)
                    if (k == a)
                        k = b;
                for (auto &k : q.v)
                    if (k == a)
                        k = b;
                edge++;
            }
    vector<int> v;

    for (auto &k : p.v)
        v.emplace_back(k);
    for (auto &k : q.v)
        v.emplace_back(k);
    while (v.size() > 10)
        v.erase(v.begin() + 5);

    return node{v, p.l, q.r, edge};
}

int n, k, m, q;

void init(int i = 1, int l = 1, int r = n)
{
    if (l == r)
        seg[i] = node{vector<int>{l}, l, r, 0};
    else
    {
        int mid = (l + r) / 2;
        init(i << 1, l, mid);
        init(i << 1 | 1, mid + 1, r);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

node query(int qL, int qR, int i = 1, int L = 1, int R = n)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (R < qL || qR < L)
        return node{vector<int>{}, 0, 0, 0};
    else
    {
        int mid = (L + R) / 2;
        return merge(query(qL, qR, i << 1, L, mid),
                     query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    fast;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        E[u].emplace_back(v);
    }
    init();
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << r - l + 1 - query(l, r).edge << '\n';
    }
}
