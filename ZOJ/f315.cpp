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

SegmentTree seg[800000];

SegmentTree *build(int index, int L, int R)
{
    if (L == R)
    {
        seg[index] = {0, L, L, nullptr, nullptr};
        return &seg[index];
    }
    int mid = (L + R) / 2;
    SegmentTree *left = build(index * 2 + 1, L, mid), *right = build(index * 2 + 2, mid + 1, R);
    seg[index] = {0, L, R, left, right};
    return &seg[index];
}

int query(SegmentTree *root, int L, int R)
{
    if (L <= root->L && root->R <= R)
        return root->val;
    if (root->left->R < L)
        return query(root->right, L, R);
    if (root->right->L > R)
        return query(root->left, L, R);
    if (L > root->R || root->L > R)
        return 0;
    return query(root->left, L, R) + query(root->right, L, R);
}

void modify(SegmentTree *root, int index, int value)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        root->val = value;
        return;
    }
    int mid = (root->L + root->R) / 2;
    if (index <= mid)
        modify(root->left, index, value);
    else
        modify(root->right, index, value);
    root->val = root->left->val + root->right->val;
}

int n;
ll sum;
vector<int> v[100005];

int main()
{
    cin >> n;
    for (int i = 1; i <= 2 * n;i++)
    {
        int k;
        cin >> k;
        v[k].emplace_back(i);
    }
    SegmentTree *root = build(0, 1, 2 * n);
    for (int i = 1; i <= n;i++)
    {
        sum += query(root, v[i][0], v[i][1]);
        modify(root, v[i][0], 1);
        modify(root, v[i][1], 1);
    }
    cout << sum << '\n';
}