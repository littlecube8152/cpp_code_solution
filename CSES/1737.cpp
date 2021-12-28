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

struct pSegTree
{
    int t, L, R;
    ll val;
    pSegTree *left, *right;
    pSegTree(int t, int L, int R, ll val, pSegTree *left, pSegTree *right) : t(t), L(L), R(R), val(val), left(left), right(right){};
    pSegTree() : val(0){};
    void modify(int i, ll val)
    {
        if (L == R)
            this->val = val;
        else
        {
            int mid = (L + R) / 2;
            if (i <= mid)
            {
                if (left->t != this->t)
                    left = new pSegTree(this->t, left->L, left->R, left->val, left->left, left->right);
                left->modify(i, val);
            }
            else
            {
                if (right->t != this->t)
                    right = new pSegTree(this->t, right->L, right->R, right->val, right->left, right->right);
                right->modify(i, val);
            }
            this->val = left->val + right->val;
        }
    }

    ll query(int qL, int qR)
    {
        if (qL <= L && R <= qR)
            return val;
        else if (qR < L || R < qL)
            return 0;
        else
            return left->query(qL, qR) + right->query(qL, qR);
    }

    void build(int arr[])
    {
        if (L == R)
            val = arr[L];
        else
        {
            int mid = (L + R) / 2;
            left = new pSegTree(t, L, mid, 0, nullptr, nullptr);
            left->build(arr);
            right = new pSegTree(t, mid + 1, R, 0, nullptr, nullptr);
            right->build(arr);
            this->val = left->val + right->val;
        }
    }
};

int n, q, arr[200005], t[2000005], tdx = 1, sdx = 1;
pSegTree *seg[200005];

signed main()
{
    fast;
    cin >> n >> q;
    seg[1] = new pSegTree(1, 1, n, 0, nullptr, nullptr);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    seg[1]->build(arr);
    t[1] = 1;
    for (int i = 1; i <= q; i++)
    {

        int type, k, a, b;
        ll x;
        cin >> type;
        if (type == 1)
        {
            cin >> k >> a >> x;
            ++tdx;
            seg[tdx] = new pSegTree(tdx, seg[t[k]]->L, seg[t[k]]->R, seg[t[k]]->val, seg[t[k]]->left, seg[t[k]]->right);
            t[k] = tdx;
            seg[t[k]]->modify(a, x);
        }
        else if (type == 2)
        {
            cin >> k >> a >> b;
            cout << seg[t[k]]->query(a, b) << '\n';
        }
        else
        {
            cin >> k;
            ++tdx;
            ++sdx;
            seg[tdx] = new pSegTree(tdx, seg[t[k]]->L, seg[t[k]]->R, seg[t[k]]->val, seg[t[k]]->left, seg[t[k]]->right);
            t[sdx] = tdx;
        }
    }
}
