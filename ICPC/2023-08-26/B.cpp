#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define double long double
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

struct node
{
    array<int, 2> one;
    array<int, 4> two;
    array<int, 8> three;
    array<array<int, 3>, 3> state;
    void init()
    {
        fill(one.begin(), one.end(), 0);
        fill(two.begin(), two.end(), 0);
        fill(three.begin(), three.end(), 0);
        for (auto &v : state)
            fill(v.begin(), v.end(), -1e9);
    }
    void flip()
    {
        swap(one[0], one[1]);
        for (int i = 0; i < 2; i++)
            swap(two[i], two[3 ^ i]);
        for (int i = 0; i < 4; i++)
            swap(three[i], three[7 ^ i]);
        swap(state[0][1], state[0][2]);
        swap(state[1][0], state[2][0]);
        swap(state[1][2], state[2][1]);
        swap(state[1][1], state[2][2]);
    }
    void assign(int val, int len)
    {
        init();
        if (val == -1)
        {
            one[0] = 1;
            if (len >= 2)
                two[0] = 1;
            if (len >= 3)
                three[0] = 1;
            state[0][1] = state[1][0] = 1;
        }
        else
        {
            one[1] = 1;
            if (len >= 2)
                two[3] = 1;
            if (len >= 3)
                three[7] = 1;
            state[0][2] = state[2][0] = 1;
        }
    }
} seg[400005], nothing;

node merge(node p, node q)
{
    node n;
    n.init();
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            n.state[i][j] = max(p.state[i][j], q.state[i][j]);
            n.state[i][j] = max(n.state[i][j], p.state[i][0] + q.state[0][j]);
            n.state[i][j] = max(n.state[i][j], p.state[i][1] + q.state[2][j]);
            n.state[i][j] = max(n.state[i][j], p.state[i][2] + q.state[1][j]);
        }
    for (int i = 0; i < 2; i++)
        n.one[i] = p.one[i] | q.one[i];

    for (int i = 0; i < 4; i++)
        n.two[i] = p.two[i] | q.two[i];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            n.two[i + j * 2] |= p.one[i] && q.one[j];

    for (int i = 0; i < 8; i++)
        n.three[i] = p.three[i] | q.three[i];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            n.three[i + j * 2] |= p.one[i] && q.two[j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            n.three[i + j * 4] |= p.two[i] && q.one[j];

    return n;
}

int n, q, ass[400005], flip[400005];
void init(int i = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        char c;
        cin >> c;
        if (c == '0')
            seg[i].assign(-1, 1);
        else
            seg[i].assign(1, 1);
    }
    else
    {
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

void push(int i, int L, int R)
{
    if (ass[i])
    {
    int mid = (L + R) / 2;
        ass[i << 1] = ass[i << 1 | 1] = ass[i];
        seg[i << 1].assign(ass[i], mid - L + 1);
        seg[i << 1 | 1].assign(ass[i], R - mid);
        ass[i] = 0;
    }
    if (flip[i])
    {
        flip[i << 1] ^= 1;
        flip[i << 1 | 1] ^= 1;
        seg[i << 1].flip();
        seg[i << 1 | 1].flip();
        flip[i] = 0;
    }
}

void assign(int mL, int mR, int val, int i = 1, int L = 1, int R = n)
{
    if (mL <= L && R <= mR)
    {
        ass[i] = val;
        flip[i] = 0;
        seg[i].assign(val, R - L + 1);
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        assign(mL, mR, val, i << 1, L, mid);
        assign(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

void flipping(int mL, int mR, int i = 1, int L = 1, int R = n)
{
    if (mL <= L && R <= mR)
    {
        flip[i] ^= 1;
        seg[i].flip();
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        flipping(mL, mR, i << 1, L, mid);
        flipping(mL, mR, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

node query(int qL, int qR, int i = 1, int L = 1, int R = n)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (R < qL || qR < L)
        return nothing;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        return merge(query(qL, qR, i << 1, L, mid),
                     query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

int Psearch(int thre)
{
    int i = 1, L = 1, R = n;
    node cur = nothing;
    while (L != R)
    {
        push(i, L, R);
        int mid = (L + R) / 2;
        node nxt = merge(cur, seg[i << 1]);
        if (nxt.state[0][0] / 2 < thre)
            L = mid + 1, cur = nxt, i = i << 1 | 1;
        else
            R = mid, i = i << 1;
    }
    return L;
}

int Ssearch(int thre)
{
    int i = 1, L = 1, R = n;
    node cur = nothing;
    while (L != R)
    {
        push(i, L, R);
        int mid = (L + R) / 2;
        node nxt = merge(seg[i << 1 | 1], cur);
        if (nxt.state[0][0] / 2 < thre)
            R = mid, cur = nxt, i = i << 1;
        else
            L = mid + 1, i = i << 1 | 1;
    }
    return R;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    nothing.init();
    cin >> n >> q;
    init();
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'F')
            flipping(l, r);
        else if (c == '0')
            assign(l, r, -1);
        else
            assign(l, r, 1);

        int x = max(0, seg[1].state[0][0]) / 2 + 1;
        cout << x << ' ';
        int y = 0;
        if (x == 1)
            y = (int)count(seg[1].one.begin(), seg[1].one.end(), 0);
        else if (x == 2)
            y = (int)count(seg[1].two.begin(), seg[1].two.end(), 0);
        else if (x == 3)
            y = (int)count(seg[1].three.begin(), seg[1].three.end(), 0);
        else
        {
            int R = Psearch(x - 2), L = Ssearch(x - 2) - 1;
            node p = query(1, L), q = query(R, n);
            y = (int)count(p.two.begin(), p.two.end(), 0) + (int)count(q.two.begin(), q.two.end(), 0);
        }
        cout << y << '\n';
    }
}