/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #define int long long
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

int n, m, f[1005][1005], vis[200005], dsu[200005], rk[200005], lazy[800005], r[200005];
pii seg[800005], pos[200005];
ll ans;
vector<pii> op;

int id(int i, int j)
{
    return (i - 1) * m + j;
}

int find(int k)
{
    return dsu[k] == k ? k : find(dsu[k]);
}

bool merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return false;
    if (rk[x] >= rk[y])
    {
        rk[x] += rk[y];
        dsu[y] = x;
        op.emplace_back(pii(x, y));
        return true;
    }
    else
        return merge(y, x);
}

void undo(pii p)
{
    auto [x, y] = p;
    rk[x] -= rk[y];
    dsu[y] = y;
}

pii merge(pii p1, pii p2)
{
    return p1.F == p2.F ? pii(p1.F, p1.S + p2.S) : min(p1, p2);
}

void apply(int i, int l)
{
    seg[i].F += l;
    lazy[i] += l;
}

void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = n * m)
{
    if (mL <= L && R <= mR)
        apply(i, val);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        if (lazy[i])
        {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

pii query(int mL, int mR, int i = 1, int L = 1, int R = n * m)
{
    if (mL <= L && R <= mR)
        return seg[i];
    else if (R < mL || mR < L)
        return {1, 0};
    else
    {
        int mid = (L + R) / 2;
        if (lazy[i])
        {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
        return merge(query(mL, mR, i << 1, L, mid),
                     query(mL, mR, i << 1 | 1, mid + 1, R));
    }
}

void build(int i = 1, int L = 1, int R = n * m)
{
    if (L != R)
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
    }
    else
        seg[i] = {0, 1};
}

bool add(int idx)
{
    // cerr << "add " << idx << '\n';
    vis[idx] = 1;
    auto [i, j] = pos[idx];
    bool flag = 1;
    for (auto [dx, dy] : vector<pii>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
        if (vis[f[i + dx][j + dy]])
            flag &= merge(f[i][j], f[i + dx][j + dy]);
    return flag;
}

void divide(int L, int R, int ansL, int ansR)
{
    // cerr << "divide " << L << ' ' << R << ' ' << ansL << ' ' << ansR << '\n';
    if (R < L)
        return;
    int mid = (L + R) / 2;

    // Assume (R, ansL] is built
    // calc  -> build [mid, R] or [mid, ansL]
    // left  -> build [mid, R] or [mid, ansL]
    // right -> build (ansL, ansmid] or (R, ansmid]

    int init = op.size();
    if (mid <= ansL)
        for (int i = mid; i <= min(R, ansL); i++)
            add(i);

    int left = op.size();
    for (r[mid] = max(mid, ansL + 1); r[mid] <= ansR; r[mid]++)
        if (!add(r[mid]))
            break;
    r[mid]--;

    while (op.size() > left)
    {
        undo(op.back());
        op.pop_back();
    }
    for (int i = max(mid, ansL + 1); i <= r[mid] + 1; i++)
    {
        vis[i] = 0;
        // cerr << "remove " << i << '\n';
    }

    divide(L, mid - 1, ansL, r[mid]);

    while (op.size() > init)
    {
        undo(op.back());
        op.pop_back();
    }
    if (mid <= ansL)
        for (int i = mid; i <= min(R, ansL); i++)
        {
            vis[i] = 0;
            // cerr << "remove " << i << '\n';
        }

    for (int i = max(R, ansL) + 1; i <= r[mid]; i++)
        add(i);

    divide(mid + 1, R, r[mid], ansR);

    while (op.size() > init)
    {
        undo(op.back());
        op.pop_back();
    }
    for (int i = max(R, ansL) + 1; i <= r[mid]; i++)
    {
        vis[i] = 0;
        // cerr << "remove " << i << '\n';
    }
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        dsu[i] = i, rk[i] = 1;
    build();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
            pos[f[i][j]] = pii(i, j);
        }
    divide(1, n * m, 1, n * m);

    for (int i = 1; i <= n; i++)
        f[i][0] = f[i][m + 1] = n * m + 1;
    for (int j = 1; j <= m; j++)
        f[0][j] = f[n + 1][j] = n * m + 1;

    // for (int i = 1; i <= n * m; i++)
        // cerr << r[i] << " \n"[i == n * m];
    for (int i = 1; i <= n * m; i++)
    {
        modify(i, n * m, 1);
        auto [x, y] = pos[i];
        for (auto [dx, dy] : vector<pii>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
            if (f[x + dx][y + dy] < i)
                modify(i, n * m, -1);
    }

    for (int i = 1; i <= n; i++)
        f[i][0] = f[i][m + 1] = 0;
    for (int j = 1; j <= m; j++)
        f[0][j] = f[n + 1][j] = 0;

    for (int i = 1; i <= n * m; i++)
    {
        pii q = query(i, r[i]);
        // cerr << q.F << ' ' << q.S << '\n';
        if (q.F == 1)
            ans += q.S;
        auto [x, y] = pos[i];
        modify(i, n * m, -1);
        for (auto [dx, dy] : vector<pii>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
            if (f[x + dx][y + dy] > i)
                modify(f[x + dx][y + dy], n * m, 1);
    }
    cout << ans << '\n';
}
