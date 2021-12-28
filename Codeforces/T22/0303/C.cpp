#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct SegTree
{
    bitset<64> val;
    int L, R;
    SegTree *left, *right;
    bool tagged;
    bitset<64> tag;
    SegTree(bitset<64> val, int L, int R, SegTree *left, SegTree *right) : val(val), L(L), R(R), left(left), right(right), tagged(0), tag(bitset<64>(0)){};
    bitset<64> getval()
    {
        if (tagged)
            return tag;
        else
            return val;
    }
    void push()
    {
        if (tagged)
        {
            if (left != nullptr)
                left->tagged = 1, left->tag = this->tag;
            if (right != nullptr)
                right->tagged = 1, right->tag = this->tag;
            this->val = this->tag, this->tagged = 0;
            this->tag = bitset<64>(0);
        }
    }
};

SegTree *build(int L, int R)
{
    if (L == R)
        return new SegTree(bitset<64>(0), L, R, nullptr, nullptr);
    int mid = (L + R) / 2;
    return new SegTree(bitset<64>(0), L, R, build(L, mid), build(mid + 1, R));
}

void modify(SegTree *r, int L, int R, int v)
{
    if (R < r->L || r->R < L)
        return;

    if ((L <= r->L && r->R <= R))
        r->tagged = 1, r->tag = bitset<64>(1LL << v);

    
    else
    {
        r->push();
        if (L <= r->L && R <= r->left->R)
            modify(r->left, L, R, v);
        else if (r->right->L <= L && r->R <= R)
            modify(r->right, L, R, v);
        else
        {
            modify(r->left, L, R, v);
            modify(r->right, L, R, v);
        }
        r->val = r->left->getval() | r->right->getval();
    }
}

bitset<64> query(SegTree *r, int L, int R)
{
    if (R < r->L || r->R < L)
        return bitset<64>(0);
    if ((L <= r->L && r->R <= R ))
        return r->getval();
    else
    {
        r->push();
        if (L <= r->L && R <= r->left->R)
            return query(r->left, L, R);
        else if (r->right->L <= L && r->R <= R)
            return query(r->right, L, R);
        else
            return query(r->left, L, R) | query(r->right, L, R);
    }
}

int n, m, in[400005], out[400005], t, a[400005], pre[400005];
vector<int> e[400005];

void dfs(int n)
{
    t++;
    in[n] = t;
    for (int i : e[n])
        if (pre[n] != i)
        {
            pre[i] = n;
            dfs(i);
        }
    t++;
    out[n] = t;
}
signed main()
{
    fast;
    cin >> n >> m;
    SegTree *root = build(1, n * 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        modify(root, in[i], in[i], a[i]);
        modify(root, out[i], out[i], a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            modify(root, in[y], out[y], z);
        }
        else
        {
            cin >> y;
            cout << query(root, in[y], out[y]).count() << '\n';
        }
    }
}