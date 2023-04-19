#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int T = 1'000'000'000;

struct node
{
    ll pL = 0, pR = 2 * T, ansR = 0, w = 0, posL = 0, sz = 0;
    bool non = 1;
    ll pos(ll k)
    {
        if (k <= pL)
            return posL;
        else if (k >= pR)
            return posL + (pR - pL);
        return posL + (k - pL);
    }
    ll weight(ll k)
    {
        assert(ansR <= pR);
        if (k >= ansR)
            return k - ansR + w;
        return w;
    }
    void increase(int t)
    {
        posL -= t, pL -= t, pR -= t, ansR -= t;
    }
};

node merge(node n1, node n2)
{
    node res;
    if (n1.non)
        return n2;
    if (n2.non)
        return n1;
    n2.increase(n1.sz);
    if (n1.posL + n1.pR - n1.pL < n2.pL)
        res = node{n1.ansR, n1.ansR, n1.ansR};
    else if (n2.pR < n1.posL)
        res = node{n1.ansR, n1.ansR, n1.ansR};
    else
    {
        if (n1.posL <= n2.pL)
            res.pL = n1.pL + n2.pL - n1.posL;
        else
            res.pL = n1.pL;

        if (n1.posL + n1.pR - n1.pL >= n2.pR)
            res.pR = n1.pL + n2.pR - n1.posL;
        else
            res.pR = n1.pR;
    }

    if (n2.ansR <= n1.posL + (n1.pR - n1.pL))
        res.ansR = min(n1.ansR, max(0LL, n2.ansR - n1.posL) + n1.pL);
    else
        res.ansR = n1.ansR;

    res.w = n1.weight(res.ansR) + n2.weight(n1.pos(res.ansR));
    res.posL = n2.pos(n1.pos(res.pL));
    res.sz = n1.sz + n2.sz;
    res.non = 0;
    return res;
}

int N, Q, pre[300005];

struct segTree
{
    vector<node> seg;
    // i: [L, R)
    void modify(int pos, node n, int i = 1, int L = 0, int R = N)
    {
        if (R - L == 1)
            seg[i] = n;
        else
        {
            int mid = (L + R) / 2;
            if (pos < mid)
                modify(pos, n, i << 1, L, mid);
            else
                modify(pos, n, i << 1 | 1, mid, R);
            seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    node query(int qL, int qR, int i = 1, int L = 0, int R = N)
    {
        if (qL <= L && R <= qR)
            return seg[i];
        else if (qR <= L || R <= qL)
            return node{};
        else
        {
            int mid = (L + R) / 2;
            return merge(query(qL, qR, i << 1, L, mid),
                         query(qL, qR, i << 1 | 1, mid, R));
        }
    }
} Rseg, Lseg;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    Rseg.seg.resize(1200005);
    Lseg.seg.resize(1200005);
    for (int i = 1; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        Rseg.modify(i, node{L, R - 1, R - 1, 0, L, 1, 0});
        Lseg.modify(N - i, node{L, R - 1, R - 1, 0, L, 1, 0});
    }
    for (int i = 1; i <= Q; i++)
    {
        int T, A, B, C, D;
        cin >> T;
        if (T == 1)
        {
            cin >> A >> B >> C;
            Rseg.modify(A, node{B, C - 1, C - 1, 0, B, 1, 0});
            Lseg.modify(N - A, node{B, C - 1, C - 1, 0, B, 1, 0});
        }
        else
        {
            cin >> A >> B >> C >> D;
            if (A < C)
            {
                // Rseg.query(A, C).debug();
                // merge(node{B, B, B, 0, B, 0}, Rseg.query(A, C)).debug();
                // merge(merge(node{B, B, B, 0, B, 0}, Rseg.query(A, C)), node{D, D, D, 0, D, 0}).debug();
                cout << merge(merge(node{B, B, B, 0, B, 0, 0}, Rseg.query(A, C)), node{D, D, D, 0, D, 0, 0}).w << '\n';
            }
            else if (C < A)
                cout << merge(merge(node{B, B, B, 0, B, 0, 0}, Lseg.query(N - A + 1, N - C + 1)), node{D, D, D, 0, D, 0, 0}).w << '\n';
            else
                cout << max(0LL, B - D) << '\n';
        }
    }
}