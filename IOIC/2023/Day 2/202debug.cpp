#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll C = 1'000'000'000;
int Q, k;
ll ans[200005], q[200005];
int has[200005], t[200005];
pii p[200005];
vector<pii> seg[800005], tree;
vector<int> l, r;
vector<pair<int, pii>> undo;

int node()
{
    tree.emplace_back(pii(0, 0));
    l.emplace_back(0);
    r.emplace_back(0);
    return (int)tree.size() - 1;
}

void modifyLi(pii val, int i = 0, ll L = 0, ll R = C)
{
    // cerr << "modifyLi " << val.F << ' ' << val.S << ' ' << L << ' ' << R << '\n';
    ll mid = (L + R) / 2;
    if (val.F * mid + val.S >= tree[i].F * mid + tree[i].S)
    {
        swap(tree[i], val);
        undo.emplace_back(make_pair(i, val));
    }
    if (val == pii(0, 0) || L == R)
        return;
    else
    {
        l[i] = node();
        r[i] = node();
        if (val.F >= tree[i].F)
            modifyLi(val, r[i], mid + 1, R);
        else
            modifyLi(val, l[i], L, mid);
    }
}

ll queryLi(ll x, int i = 0, ll L = 0, ll R = C)
{
    // cerr << "queryLi " << tree[i].F << ' ' << tree[i].S << x << ' ' << L << ' ' << R << '\n';
    ll mid = (L + R) / 2;
    if (x <= mid && l[i] != 0)
        return max(x * tree[i].F + tree[i].S, queryLi(x, l[i], L, mid));
    if (x > mid && r[i] != 0)
        return max(x * tree[i].F + tree[i].S, queryLi(x, r[i], mid + 1, R));

    return x * tree[i].F + tree[i].S;
}

void modify(int mL, int mR, pii val, int i = 1, int L = 1, int R = Q)
{
    // cerr << "modify " << val.F << ' ' << val.S << ' ' << mL << ' ' << mR << '\n';
    if (mL <= L && R <= mR)
        seg[i].emplace_back(val);
    else if (mR < L || R < mL)
        return;
    else
    {
        ll mid = (L + R) / 2;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
    }
}

void traverse(int i = 1, int L = 1, int R = Q)
{
    // cerr << "traverse " << i << ' ' << L << ' ' << R << '\n';
    if (L == R)
    {
        if (t[L] == 0)
            ans[L] = queryLi(q[L]);
        // cerr << "query " << L << ' ' <<  t[L] << ' ' << q[L] << '\n';
    }
    else
    {
        ll mid = (L + R) / 2;
        int init = undo.size();
        for (auto p : seg[i])
            modifyLi(p);
        traverse(i << 1, L, mid);
        traverse(i << 1 | 1, mid + 1, R);
        while (undo.size() > init)
        {
            auto [i, p] = undo.back();
            tree[i] = p;
            undo.pop_back();
        }
    }
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    cin >> Q;
    tree.reserve(400005);
    l.reserve(400005);
    r.reserve(400005);
    node();

    for (int i = 1; i <= Q; i++)
    {
        ll a, b;
        t[i] = rd() % 2;
        if (t[i] == 0)
            q[i] = rd() % C;
        else if (t[i] == 1)
        {
            p[k] = pll(rd() % C, rd() % C);
            has[k++] = i;
        }
    }
    for (int i = 0; i <= Q; i++)
        if (has[i])
            modify(has[i], Q, p[i]);

    traverse();

    for (int i = 1; i <= Q; i++)
        if (t[i] == 0)
        {
            if (ans[i] > 0)
                cout << ans[i] << '\n';
            else
                cout << "double is good at problem setting\n";
        }
}