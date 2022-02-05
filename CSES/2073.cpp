/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

bool random(int left, int right)
{
    return (abs((ll)rd()) % (left + right) < left);
}

struct treap
{
    int pri, size;
    char c;
    treap *l, *r;

    treap(char c) : pri(rd()), size(1), c(c), l(nullptr), r(nullptr){};
    treap() : pri(rd()), size(1), c(' '), l(nullptr), r(nullptr){};

    void pull()
    {
        size = (l == nullptr ? 0 : l->size) + (r == nullptr ? 0 : r->size) + 1;
    }

    void print()
    {
        if (l != nullptr)
            l->print();
        cout << c;
        if (r != nullptr)
            r->print();
    }
};

void spilt(int cnt, treap *root, treap *&left, treap *&right)
{
    /*
    cout << "spilt remain " << cnt << " root = ";
    if (root == nullptr)
        cout << "_";
    else
        root->print();
    cout << '\n';
    */

    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    int lsize = (root->l != nullptr ? root->l->size : 0);
    //cout << "lsize = " << lsize << " rsize = " << rsize << '\n';
    if (cnt >= lsize + 1)
    {
        left = root;
        spilt(cnt - lsize - 1, left->r, left->r, right);
        left->pull();
    }
    else
    {
        right = root;
        spilt(cnt, right->l, left, right->l);
        right->pull();
    }
}

treap *merge(treap *left, treap *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    if (left->pri < right->pri)
    {
        left->r = merge(left->r, right);
        left->pull();
        return left;
    }
    else
    {
        right->l = merge(left, right->l);
        right->pull();
        return right;
    }
}

int n, q, a, b;
string s;
treap *root;

signed main()
{
    //fast;
    cin >> n >> q;
    cin >> s;
    root = new treap(s[0]);
    for (int i = 1; i < n; i++)
        root = merge(root, new treap(s[i]));
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b;
        treap *left, *mid, *right;
        spilt(a - 1, root, left, mid);
        spilt(b - a + 1, mid, mid, right);
        left = merge(left, right);
        root = merge(left, mid);
    }
    root->print();
    cout << '\n';
}
