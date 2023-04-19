#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int P = 18;
int N, K, M, Q;
pii sp[100005][P], seg[P][400005], range[P][100005];

pii merge(pii p1, pii p2)
{
    return pii(min(p1.F, p2.F), max(p1.S, p2.S));
}

void build(int p, int i = 1, int L = 1, int R = N)
{
    if (L == R)
        seg[p][i] = range[p][L];
    else
    {
        int mid = (L + R) / 2;
        build(p, i << 1, L, mid);
        build(p, i << 1 | 1, mid + 1, R);
        seg[p][i] = merge(seg[p][i << 1], seg[p][i << 1 | 1]);
    }
}

pii query(int qL, int qR, int p, int i = 1, int L = 1, int R = N)
{
    if (R < qL || qR < L)
        return pii(N + 1, 0);
    else if (qL <= L && R <= qR)
        return seg[p][i];
    else
    {
        int mid = (L + R) / 2;
        return merge(query(qL, qR, p, i << 1, L, mid),
                     query(qL, qR, p, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> M;
    for (int i = 0; i < P; i++)
        for (int j = 1; j <= N; j++)
            sp[j][i] = pii(N + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        int A, B, lg;
        cin >> A >> B;
        lg = __lg(min(abs(B - A) + 1, K));
        if (A < B)
        {
            sp[A][lg].S = max(sp[A][lg].S, B);
            sp[min(B, A + K - 1) - (1 << lg) + 1][lg].S = max(sp[min(B, A + K - 1) - (1 << lg) + 1][lg].S, B);
        }
        else
        {
            sp[A - (1 << lg) + 1][lg].F = min(sp[A - (1 << lg) + 1][lg].F, B);
            sp[max(B, A - K + 1)][lg].F = min(sp[max(B, A - K + 1)][lg].F, B);
        }
    }
    for (int i = P - 1; i > 0; i--)
        for (int j = 1; j + (1 << i) - 1 <= N; j++)
        {
            sp[j][i - 1] = merge(sp[j][i - 1], sp[j][i]);
            int k = j + (1 << (i - 1));
            sp[k][i - 1] = merge(sp[k][i - 1], sp[j][i]);
        }
    for (int j = 1; j <= N; j++)
        range[0][j].F = min(sp[j][0].F, j), range[0][j].S = max(sp[j][0].S, j);
    for (int j = 1; j < P; j++)
    {
        build(j - 1);
        for (int i = 1; i <= N; i++)
            range[j][i] = query(range[j - 1][i].F, range[j - 1][i].S, j - 1);
    }
    build(P - 1);
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int L, R, T, ans = 0;
        cin >> L >> T;
        R = L;
        for (int j = P - 1; j >= 0; j--)
        {
            pii p = query(L, R, j);
            if (T < p.F || p.S < T)
                tie(L, R) = p, ans += (1 << j);
        }
        cout << (ans > N ? -1 : ans + 1) << '\n';
    }
}