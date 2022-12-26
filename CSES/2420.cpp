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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const ll base = 29, mod = 1234567891;
ll p[200005];
int n, m, t, l, r;
char c;

struct segTree
{
    pll seg[800005];
    void init(int i = 1, int L = 0, int R = n)
    {
        seg[i] = pll(0, R - L + 1);
        if (L == R)
            return;
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
    }
    inline pll merge(pll l, pll r)
    {
        return pll((l.F * p[r.S] + r.F) % mod, l.S + r.S);
    }
    void modify(int pos, char c, int i = 1, int L = 0, int R = n)
    {
        if (L == R)
            seg[i] = pll(c - 'a', 1);
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, c, i << 1, L, mid);
            else
                modify(pos, c, i << 1 | 1, mid + 1, R);
            seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    pll query(int qL, int qR, int i = 1, int L = 0, int R = n)
    {
        if (R < qL || qR < L)
            return pll(0, 0);
        else if (qL <= L && R <= qR)
            return seg[i];
        else
        {
            int mid = (L + R) / 2;
            return merge(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} seg1, seg2;

signed main()
{
    fast;
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * base % mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        seg1.modify(i, c);
        seg2.modify(n - i, c);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> l >> c;
            seg1.modify(l, c);
            seg2.modify(n - l, c);
        }
        else
        {
            cin >> l >> r;
            cout << (seg1.query(l, r) == seg2.query(n - r, n - l) ? "YES\n" : "NO\n");
        }
    }
}
