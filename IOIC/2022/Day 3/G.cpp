#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXC = 100005;
const int INF = 2147483647;
struct node
{
    ll sum;
    int mx, mxcnt, smx, lazy;
    node(int k = 0) : sum(k), mx(k), mxcnt(1), smx(-INF), lazy(-1)
    {
    }
    node operator+(const node &a) const
    {
        node rt;
        rt.sum = sum ^ a.sum;
        rt.mx = max(mx, a.mx);
        if (mx == a.mx)
        {
            rt.mxcnt = mxcnt + a.mxcnt;
            rt.smx = max(smx, a.smx);
        }
        else if (mx > a.mx)
        {
            rt.mxcnt = mxcnt;
            rt.smx = max(smx, a.mx);
        }
        else
        {
            rt.mxcnt = a.mxcnt;
            rt.smx = max(mx, a.smx);
        }
        rt.lazy = -1;
        return rt;
    }
} seg[MAXC << 2];

int a[MAXC];

void give_tag(int rt, int t)
{
    if (t >= seg[rt].mx)
        return;
    seg[rt].lazy = t;
    if (seg[rt].mxcnt % 2 == 1)
        seg[rt].sum = seg[rt].sum ^ (seg[rt].mx ^ t);
    seg[rt].mx = t;
}

void tag_down(int rt)
{
    if (seg[rt].lazy == -1)
        return;
    give_tag(rt << 1, seg[rt].lazy);
    give_tag(rt << 1 | 1, seg[rt].lazy);
    seg[rt].lazy = -1;
}

void build(int l, int r, int rt)
{
    if (l == r)
        return seg[rt] = node(a[l]), void();
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void modify(int L, int R, int l, int r, int rt, int t)
{
    if (L <= l && R >= r && t > seg[rt].smx)
        return give_tag(rt, t);
    if (l != r)
        tag_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid)
        modify(L, R, l, mid, rt << 1, t);
    if (R > mid)
        modify(L, R, mid + 1, r, rt << 1 | 1, t);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

node query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return seg[rt];
    if (l != r)
        tag_down(rt);
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r,
                                                rt << 1 | 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, n, 1);
    while (q--)
    {
        int k, l, r, t;
        cin >> k >> l >> r;
        if (k == 0)
            cin >> t, modify(l, r, 1, n, 1, t);
        else if (k == 1)
            cout << query(l, r, 1, n, 1).sum << "\n";
    }
}