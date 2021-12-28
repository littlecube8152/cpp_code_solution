#pragma GCC optimize("O3,unroll-loops")
#pragma pack(0)

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

struct Treap
{
    long long pri, key, size;
    Treap *left, *right;
    Treap(int value) : pri(rd()), key(value), size(1){};
    long long safe_left_size()
    {
        return this->left == nullptr ? 0 : this->left->size;
    }

    long long safe_right_size()
    {
        return this->right == nullptr ? 0 : this->right->size;
    }

    void pull()
    {
        this->size = safe_left_size() + safe_right_size() + 1;
    }
};
Treap *merge(Treap *less, Treap *greater)
{
    if (less == nullptr)
        return greater;
    else if (greater == nullptr)
        return less;
    else if (less->pri < greater->pri)
    {
        less->right = merge(less->right, greater);
        less->pull();
        return less;
    }
    else
    {
        greater->left = merge(less, greater->right);
        greater->pull();
        return greater;
    }
}
void spilt_by_value_less(Treap *root, int value, Treap *&less, Treap *&greater)
{
    if (root == nullptr)
        return;
    else if (root->key < value)
    {
        less = root;
        spilt_by_value_less(root->right, value, less->right, greater);
        less->pull();
    }
    else
    {
        greater = root;
        spilt_by_value_less(root->left, value, less, greater->left);
        greater->pull();
    }
}
void spilt_by_size(Treap *root, int size, Treap *&less, Treap *&greater)
{
    if (root == nullptr)
        return;
    else if (root->safe_left_size() + 1 >= size)
    {
        less = root;
        spilt_by_size(root->right, size - root->safe_left_size() + 1, less->right, greater);
    }
    else
    {
        greater = root;
        spilt_by_size(root->left, size, less, greater->left);
    }
}

int n, dp[2000005], l[1000005], r[1000005], w[1000005];
vector<int> v;
vector<pii> trans[2000005];

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        v.emplace_back(l[i]);
        v.emplace_back(r[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
    {
        l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
        r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
        trans[r[i]].emplace_back(pii{l[i], w[i]});
    }
    for (int i = 1; i <= v.size(); i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        for (auto p : trans[i])
            dp[i] = max(dp[i], dp[p.F - 1] + p.S);
    }
    cout << dp[v.size()] << '\n';
}