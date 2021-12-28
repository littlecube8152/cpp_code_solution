//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct SegmentTree
{
    int val, L, R;
    SegmentTree *left, *right;
};

int a[1000005];
SegmentTree seg[4000000];

SegmentTree *build(int index, int L, int R)
{
    if (L == R)
    {
        seg[index] = {a[L], L, R, nullptr, nullptr};
        return &seg[index];
    }
    int mid = (L + R) / 2;
    SegmentTree *left = build(index * 2 + 1, L, mid), *right = build(index * 2 + 2, mid + 1, R);
    seg[index] = {min(left->val, right->val), L, R, left, right};
    return &seg[index];
}

int query(SegmentTree *root, int L, int R)
{
    if (root->right == nullptr && root->left == nullptr)
        return root->val;
    if (L <= root->L && root->R <= R)
        return root->val;
    if (L > root->left->R)
        return query(root->right, L, R);
    if (R < root->right->L)
        return query(root->left, L, R);
    if (L > root->R || root->L > R)
        return 0;
    return min(query(root->right, L, R), query(root->left, L, R));
}

int n;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree *root = build(0, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << query(root, x, y) + 1 << '\n';
    }
}