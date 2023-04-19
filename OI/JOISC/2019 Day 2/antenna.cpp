#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll inf = 4'000'000'000;
const pll emp = {inf, -inf};
vector<pii> qu[200005];
vector<int> in[200005], out[200005];
int N, Q, A[200005], B[200005], H[200005];
ll ans[200005];

struct node
{
    ll res = -1;
    pll h = emp, l = emp;

    void applyH(ll H)
    {
        if (abs(H) == inf)
            return;
        h.F = min(h.F, H), h.S = max(h.S, H);
    }

} seg[800005];

node calc(node n)
{
    if (n.h != emp && n.l != emp)
        n.res = max({n.res,
                     abs(n.h.F - n.l.F),
                     abs(n.h.S - n.l.F),
                     abs(n.h.F - n.l.S),
                     abs(n.h.S - n.l.S)});
    return node{n.res, emp, n.l};
}

void push(int i)
{
    seg[i << 1].applyH(seg[i].h.F);
    seg[i << 1].applyH(seg[i].h.S);
    seg[i << 1 | 1].applyH(seg[i].h.F);
    seg[i << 1 | 1].applyH(seg[i].h.S);
    seg[i] = calc(seg[i]);
}

void pull(int i)
{
    seg[i].res = max({seg[i].res, calc(seg[i << 1]).res, calc(seg[i << 1 | 1]).res});
}

void toggle(int pos, ll h, bool on, int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        if (on)
        {
            seg[i] = calc(seg[i]);
            seg[i].l = pll(h, h);
        }
        else
        {
            seg[i] = calc(seg[i]);
            seg[i].l = emp;
        }
    }
    else
    {
        int mid = (L + R) / 2;
        push(i);
        if (pos <= mid)
            toggle(pos, h, on, i << 1, L, mid);
        else
            toggle(pos, h, on, i << 1 | 1, mid + 1, R);
        pull(i);
        seg[i].l.F = min(seg[i << 1].l.F, seg[i << 1 | 1].l.F);
        seg[i].l.S = max(seg[i << 1].l.S, seg[i << 1 | 1].l.S);
    }
}

void modify(int mL, int mR, ll h, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        seg[i].applyH(h);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i);
        modify(mL, mR, h, i << 1, L, mid);
        modify(mL, mR, h, i << 1 | 1, mid + 1, R);
        pull(i);
    }
}

ll query(int mL, int mR, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        return calc(seg[i]).res;
    else if (R < mL || mR < L)
        return -1;
    else
    {
        int mid = (L + R) / 2;
        push(i);
        return max(query(mL, mR, i << 1, L, mid),
                   query(mL, mR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i] >> A[i] >> B[i];
        if (i + A[i] <= N)
            in[i + A[i]].emplace_back(i);
        if (i + B[i] <= N)
            out[i + B[i]].emplace_back(i);
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int L, R;
        cin >> L >> R;
        qu[R].emplace_back(pii(i, L));
    }
    for (int i = 1; i <= N; i++)
    {
        for (auto j : in[i])
            toggle(j, H[j], 1);
        modify(max(0, i - B[i]), max(0, i - A[i]), H[i]);
        for (auto [j, L] : qu[i])
            ans[j] = query(L, i);
        for (auto j : out[i])
            toggle(j, H[j], 0);
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}
