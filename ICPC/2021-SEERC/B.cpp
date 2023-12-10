#include <bits/stdc++.h>
using namespace std;

struct node
{
    int m[16], type[4], lazy[4];

    void tag(int k, int t, int v)
    {
        if (type[k] == 2 && t == 1)
            t = 2, v += lazy[k];
        if (t == 1)
        {
            type[k] = 1, lazy[k] += v;
            for (int i = 0; i < 16; i++)
                if (i >> k & 1)
                    m[i] += v;
        }
        else
        {
            type[k] = 2, lazy[k] = v;
            for (int i = 0; i < 16; i++)
                if (i >> k & 1)
                    m[i] = m[i ^ (1 << k)] + v;
        }
    }

    void init()
    {
        fill(m, m + 16, 0);
        fill(type, type + 4, 0);
        fill(lazy, lazy + 4, 0);
    }

    void pull(node &l, node &r)
    {
        for (int i = 0; i < 16; i++)
            m[i] = min(l.m[i], r.m[i]);
    }

    void push(node &l, node &r)
    {
        for (int i = 0; i < 4; i++)
            if (type[i])
                l.tag(i, type[i], lazy[i]), r.tag(i, type[i], lazy[i]);
        fill(type, type + 4, 0);
        fill(lazy, lazy + 4, 0);
    }
} seg[1000006];

int N, Q, K, A[250005][4], isq[20004], ans[20004];
vector<array<int, 6>> E[20004];

void build(int i = 1, int L = 1, int R = N)
{
    seg[i].init();

    if (L != R)
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
        seg[i].pull(seg[i << 1], seg[i << 1 | 1]);
    }
    else
    {
        for (int j = 0; j < 4; j++)
            seg[i].tag(j, 2, A[L][j]);
    }
}

void modify(int p, int qL, int qR, int t, int x, vector<pair<int, node>> &ch, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
    {
        ch.emplace_back(i, seg[i]);
        seg[i].tag(p, t, x);
    }
    else if (R < qL || qR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        ch.emplace_back(i, seg[i]);
        ch.emplace_back(i << 1, seg[i << 1]);
        ch.emplace_back(i << 1 | 1, seg[i << 1 | 1]);
        seg[i].push(seg[i << 1], seg[i << 1 | 1]);
        modify(p, qL, qR, t, x, ch, i << 1, L, mid);
        modify(p, qL, qR, t, x, ch, i << 1 | 1, mid + 1, R);
        seg[i].pull(seg[i << 1], seg[i << 1 | 1]);
    }
}

int query(int qL, int qR, vector<pair<int, node>> &ch, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return seg[i].m[15];
    else if (R < qL || qR < L)
        return 1e9;
    else
    {
        int mid = (L + R) / 2;
        ch.emplace_back(i, seg[i]);
        ch.emplace_back(i << 1, seg[i << 1]);
        ch.emplace_back(i << 1 | 1, seg[i << 1 | 1]);
        seg[i].push(seg[i << 1], seg[i << 1 | 1]);
        return min(query(qL, qR, ch, i << 1, L, mid),
                   query(qL, qR, ch, i << 1 | 1, mid + 1, R));
    }
}

void dfs(int u)
{
    for (auto [v, t, p, l, r, x] : E[u])
    {
        vector<pair<int, node>> ch;
        if (t <= 2)
        {
            modify(p, l, r, t, x, ch);
            dfs(v);
        }
        else
            ans[v] = query(l, r, ch);
        reverse(ch.begin(), ch.end());
        for (auto [i, s] : ch)
            seg[i] = s;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> K >> N >> Q;
    for (int i = 0; i < K; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[j][i];
    for (int i = 1; i <= Q; i++)
    {
        int ty, ti, p = 1, l, r, x = 0;
        cin >> ty;
        if (ty <= 2)
            cin >> ti >> p >> l >> r >> x;
        else
            isq[i] = 1, cin >> ti >> l >> r;
        E[ti].push_back({i, ty, p - 1, l, r, x});
    }

    build();
    dfs(0);

    for (int i = 1; i <= Q; i++)
        if (isq[i])
            cout << ans[i] << '\n';
}