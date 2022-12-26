#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, M, Q, jump[2][100005][30];
vector<pll> line[2];

struct segTree
{
    int seg[200005] = {}, lazy[200005] = {};
    void build(bool change, int i = 1, int L = 1, int R = N)
    {
        if (L == R)
            seg[i] = L;
        else
        {
            int mid = (L + R) / 2;
            build(change, i + 1, L, mid);
            build(change, i + 2 * (mid - L + 1), mid + 1, R);
            if (!change)
                seg[i] = max(seg[i + 1], seg[i + 2 * (mid - L + 1)]);
            else
                seg[i] = min(seg[i + 1], seg[i + 2 * (mid - L + 1)]);
        }
    }

    void modify(bool change, int mL, int mR, int val, int i = 1, int L = 1, int R = N)
    {
        if (mL > mR)
            swap(mL, mR);
        if (mL <= L && R <= mR)
            lazy[i] = val;
        else if (R < mL || mR < L)
            return;
        else
        {
            int mid = (L + R) / 2;
            if (lazy[i])
            {
                seg[i] = lazy[i];
                lazy[i + 1] = lazy[i];
                lazy[i + 2 * (mid - L + 1)] = lazy[i];
                lazy[i] = 0;
            }
            modify(change, mL, mR, val, i + 1, L, mid);
            modify(change, mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
            if (!change)
                seg[i] = max((lazy[i + 1] ? lazy[i + 1] : seg[i + 1]),
                             (lazy[i + 2 * (mid - L + 1)] ? lazy[i + 2 * (mid - L + 1)] : seg[i + 2 * (mid - L + 1)]));
            else
                seg[i] = min((lazy[i + 1] ? lazy[i + 1] : seg[i + 1]),
                             (lazy[i + 2 * (mid - L + 1)] ? lazy[i + 2 * (mid - L + 1)] : seg[i + 2 * (mid - L + 1)]));
        }
    }

    int query(bool change, int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (qL > qR)
            swap(qL, qR);
        if (qL <= L && R <= qR)
            return (lazy[i] ? lazy[i] : seg[i]);
        else if (R < qL || qR < L)
            return (!change ? 0 : 1e9);
        else
        {
            int mid = (L + R) / 2;
            if (lazy[i])
            {
                seg[i] = lazy[i];
                lazy[i + 1] = lazy[i];
                lazy[i + 2 * (mid - L + 1)] = lazy[i];
                lazy[i] = 0;
            }
            int res = (!change ? max(query(change, qL, qR, i + 1, L, mid), query(change, qL, qR, i + 2 * (mid - L + 1), mid + 1, R)) : min(query(change, qL, qR, i + 1, L, mid), query(change, qL, qR, i + 2 * (mid - L + 1), mid + 1, R)));
            seg[i] = max((lazy[i + 1] ? lazy[i + 1] : seg[i + 1]),
                         (lazy[i + 2 * (mid - L + 1)] ? lazy[i + 2 * (mid - L + 1)] : seg[i + 2 * (mid - L + 1)]));
            return res;
        }
    }
} tree[2][21];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++)
    {
        int A, B;
        cin >> A >> B;
        if (A < B)
            line[0].emplace_back(pii{A, B});
        else
            line[1].emplace_back(pii{B, A});
    }
    sort(line[0].begin(), line[0].end(), [](pii p1, pii p2)
         { return p1.S < p2.S; });
    sort(line[1].begin(), line[1].end(), [](pii p1, pii p2)
         { return p1.F > p2.F; });

    for (int mx = 0; mx <= 1; mx++)
    {
        tree[mx][0].build(mx);
        for (int i = 0; i < line[mx].size(); i++)
            if (mx == 0)
                tree[mx][0].modify(mx, line[mx][i].F, line[mx][i].S, line[mx][i].S);
            else
                tree[mx][0].modify(mx, line[mx][i].F, line[mx][i].S, line[mx][i].F);
        for (int i = 1; i <= N; i++)
            jump[mx][i][0] = tree[mx][0].query(mx, i, i);
        for (int p = 1; p <= 20; p++)
        {
            for (int i = 1; i <= N; i++)
                tree[mx][p - 1].modify(mx, i, i, jump[mx][i][p - 1]);
            for (int i = 1; i <= N; i++)
                jump[mx][i][p] = tree[mx][p - 1].query(mx, i, jump[mx][i][p - 1]);
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int S, cur, T, ans = 0, mx;
        cin >> S >> T;
        if (S < T)
        {
            mx = 0;
            cur = S;
            for (int p = 19; p >= 0; p--)
                if (tree[mx][p].query(mx, S, cur) < T)
                    ans += (1 << p), cur = tree[mx][p].query(mx, S, cur);
            if (tree[mx][0].query(mx, S, cur) >= T)
                cout << ans + 1 << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            mx = 1;
            cur = S;
            for (int p = 19; p >= 0; p--)
                if (tree[mx][p].query(mx, S, cur) > T)
                    ans += (1 << p), cur = tree[mx][p].query(mx, S, cur);
            if (tree[mx][0].query(mx, S, cur) <= T)
                cout << ans + 1 << '\n';
            else
                cout << -1 << '\n';
        }
    }
}