/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct node
{
    int A, B, AB, BA;
    void flip()
    {
        swap(A, B);
        swap(AB, BA);
    }
} seg[3000006];

node merge(node a, node b)
{
    return node{a.A + b.A,
                a.B + b.B,
                max(a.AB + b.B, a.A + b.AB),
                max(a.BA + b.A, a.B + b.BA)};
}

int n, q, a[1000006], lazy[3000006];

void init(int i = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        if (a[L] == 4)
            seg[i] = node{1, 0, 1, 1};
        else
            seg[i] = node{0, 1, 1, 1};
    }
    else
    {
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

void modify(int mL, int mR, int i = 1, int L = 1, int R = n)
{
    if (mL <= L && R <= mR)
    {
        lazy[i] ^= 1;
        seg[i].flip();
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        if (lazy[i])
        {
            lazy[i << 1] ^= 1;
            seg[i << 1].flip();
            lazy[i << 1 | 1] ^= 1;
            seg[i << 1 | 1].flip();
            lazy[i] = 0;
        }
        int mid = (L + R) / 2;
        modify(mL, mR, i << 1, L, mid);
        modify(mL, mR, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    init();
    for (int i = 1; i <= q; i++)
    {
        string s;
        int l, r;
        cin >> s;
        if (s == "count")
        {
            cout << seg[1].AB << '\n';
        }
        else
        {
            cin >> l >> r;
            modify(l, r);
        }
    }
}
