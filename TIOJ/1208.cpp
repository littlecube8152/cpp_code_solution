#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Treap
{
    ll pri, key, size;
    Treap *left, *right;
    Treap(ll k) : pri(rand()), key(k), size(1), left(nullptr), right(nullptr) {}
    void pull()
    {
        this->size = 1;
        if (this->left != nullptr)
            this->size += this->left->size;
        if (this->right != nullptr)
            this->size += this->right->size;
    }
};
inline ll size(Treap *p)
{
    if (p == nullptr)
        return 0;
    return p->size;
}
Treap *merge(Treap *a, Treap *b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    if (a->pri < b->pri)
    {
        a->right = merge(a->right, b);
        a->pull();
        return a;
    }
    else
    {
        b->left = merge(a, b->left);
        b->pull();
        return b;
    }
}

void split(Treap *p, Treap *&a, Treap *&b, ll k)
{

    if (p == nullptr)
    {
        a = nullptr, b = nullptr;
        return;
    }
    if (p->key <= k)
    {
        a = p;
        split(p->right, a->right, b, k);
        a->pull();
    }
    else
    {
        b = p;
        split(p->left, a, b->left, k);
        b->pull();
    }
}
void del(Treap *p)
{
    if(p->left!=nullptr)
        del(p->left);
    if(p->right!=nullptr)
        del(p->right);
    delete p;
}

ll a[200005], n, k;

ll bs(ll L, ll R, ll k)
{
    //cout << "BS " << L << " to " << R << '\n';
    if (L == R)
        return L;
    ll mid = (L + R) / 2, result = 0;
    if (mid == L)
        mid = R;
    Treap *root = nullptr;
    for (int i = 0; i <= n; i++)
    {
        Treap *less = nullptr, *greater = nullptr, *self = new Treap(a[i]);
        split(root, less, greater, a[i] - mid);
        result += size(less);
        //cout << "BS mid " << mid << " " << result << '\n';
        root = merge(less, greater);
        split(root, less, greater, a[i]);
        less = merge(less, self);
        root = merge(less, greater);
    }
    del(root);

    if (mid == R)
    {
        if (result == k)
            return R;
        else
            return L;
    }

    else if (result >= k)
        return bs(mid, R, k);
    else
        return bs(L, mid, k);
}

signed main()
{
    fast;
    while (cin >> n >> k)
    {
        ll pos = 0, neg = 0;
        if (n == 0 && k == 0)
            return 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        ll result = bs(-200000000, 200000000, k);
        cout << result << '\n';
    }
}