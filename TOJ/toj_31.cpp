/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0LL), cin.tie(0LL)
using namespace std;
//using namespace __gnu_pbds;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

struct Treap
{
    bool reverse, hasLazy;
    ll pri, val, size, sum, LmxSum, RmxSum, mxSum, lazy;
    Treap *left, *right;
    Treap(int val) : reverse(0LL), hasLazy(0LL), pri(rd()), val(val), size(1), sum(val), LmxSum(max(0, val)), RmxSum(max(0, val)), mxSum(max(0, val)), lazy(0), left(nullptr), right(nullptr){};

    void pull()
    {
        size = (left == nullptr ? 0LL : left->size) + (right == nullptr ? 0LL : right->size) + 1;
        sum = (left == nullptr ? 0LL : left->sum) + (right == nullptr ? 0LL : right->sum) + val;

        if (left == nullptr)
            LmxSum = max({0LL,
                          val,
                          val + (right == nullptr ? 0LL : right->LmxSum)});
        else
            LmxSum = max({0LL,
                          left->LmxSum,
                          left->sum,
                          left->sum + val,
                          left->sum + val + (right == nullptr ? 0LL : right->LmxSum)});

        if (right == nullptr)
            RmxSum = max({0LL,
                          val,
                          val + (left == nullptr ? 0LL : left->RmxSum)});
        else
            RmxSum = max({0LL,
                          right->RmxSum,
                          right->sum,
                          right->sum + val,
                          right->sum + val + (left == nullptr ? 0LL : left->RmxSum)});

        mxSum = max({0LL,
                     (left == nullptr ? 0LL : left->mxSum),
                     (right == nullptr ? 0LL : right->mxSum),
                     max(0LL, (left == nullptr ? 0LL : left->RmxSum)) + val + max(0LL, (right == nullptr ? 0LL : right->LmxSum))});
    }

    void push()
    {
        if (reverse)
        {
            if (left != nullptr)
                left->reverse = !left-> reverse;
            if (right != nullptr)
                right->reverse = !right->reverse;
            swap(left, right);
            reverse = false;
        }
        if (hasLazy)
        {
            val = lazy;
            if (left != nullptr)
            {
                left->hasLazy = true;
                left->lazy = lazy;
                left->LmxSum = left->RmxSum = left->mxSum = left->size * max(lazy, 0LL);
                left->sum = left->size * lazy;
            }
            if (right != nullptr)
            {
                right->hasLazy = true;
                right->lazy = lazy;
                right->LmxSum = right->RmxSum = right->mxSum = right->size * max(lazy, 0LL);
                right->sum = right->size * lazy;
            }
            hasLazy = false;
        }
    }

    void debug()
    {
        //if (left != nullptr)
        //    left->debug();
        //cout << "[" << val << "]";
        //if (right != nullptr)
        //    right->debug();
    }
};

Treap *merge(Treap *less_key, Treap *large_key)
{

    if (less_key == nullptr)
    {
        if (large_key != nullptr)
            large_key->push();
        return large_key;
    }
    if (large_key == nullptr)
    {
        if (less_key != nullptr)
            less_key->push();
        return less_key;
    }
    if (less_key->pri < large_key->pri)
    {
        less_key->push();
        less_key->right = merge(less_key->right, large_key);
        less_key->pull();
        return less_key;
    }
    else
    {
        large_key->push();
        large_key->left = merge(less_key, large_key->left);
        large_key->pull();
        return large_key;
    }
}

Treap *safe_merge(Treap *less_key, Treap *large_key)
{
    Treap *tmp = merge(less_key, large_key);
    return tmp;
}

void spilt_by_size(Treap *root, Treap *&less, Treap *&large, int less_size)
{
    if (root == nullptr)
    {
        less = large = nullptr;
        return;
    }
    root->push();
    if ((root->left == nullptr ? 0LL : root->left->size) + 1 <= less_size)
    {
        less = root;
        spilt_by_size(root->right, less->right, large, less_size - (root->left == nullptr ? 0LL : root->left->size) - 1);
        less->pull();
    }
    else
    {
        large = root;
        spilt_by_size(root->left, less, large->left, less_size);
        large->pull();
    }
}

void del(Treap *root)
{
    if (root->left != nullptr)
        del(root->left);
    if (root->right != nullptr)
        del(root->right);
    delete root;
}

int N, M, p, k, l;
string op;
signed main()
{
    fast;
    cin >> N >> M;
    cin >> p;
    Treap *root = new Treap(p);
    for (int i = 2; i <= N; i++)
    {
        cin >> p;
        Treap *tmp = new Treap(p);
        root = safe_merge(root, tmp);
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> op;
        if (op == "INSERT")
        {
            cin >> p >> k;
            Treap *left, *right;
            spilt_by_size(root, left, right, p);
            for (int j = 1; j <= k; j++)
            {
                cin >> l;
                Treap *tmp = new Treap(l);
                left = safe_merge(left, tmp);
            }
            root = safe_merge(left, right);
        }
        if (op == "DELETE")
        {
            cin >> p >> k;
            Treap *left, *right, *mid;
            spilt_by_size(root, left, right, p - 1);
            spilt_by_size(right, mid, right, k);
            if (mid != nullptr)
                del(mid);
            root = safe_merge(left, right);
        }
        if (op == "MAKE-SAME")
        {
            cin >> p >> k >> l;
            Treap *left, *right, *mid;
            spilt_by_size(root, left, right, p - 1);
            spilt_by_size(right, mid, right, k);
            mid->hasLazy = true;
            mid->lazy = l;
            mid->LmxSum = mid->RmxSum = mid->mxSum = mid->size * max(l, 0);
            mid->sum = mid->size * l;
            right = safe_merge(mid, right);
            root = safe_merge(left, right);
        }
        if (op == "REVERSE")
        {
            cin >> p >> k;
            Treap *left, *right, *mid;
            spilt_by_size(root, left, right, p - 1);
            spilt_by_size(right, mid, right, k);
            mid->reverse ^= 1;
            right = safe_merge(mid, right);
            root = safe_merge(left, right);
        }
        if (op == "GET-SUM")
        {
            cin >> p >> k;
            Treap *left, *right, *mid;

            spilt_by_size(root, left, right, p - 1);
            spilt_by_size(right, mid, right, k);
            cout << mid->sum << '\n';
            right = safe_merge(mid, right);
            root = safe_merge(left, right);
        }
        if (op == "MAX-SUM")
            cout << root->mxSum << '\n';
    }
}
