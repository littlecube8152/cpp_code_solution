#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const ll INF = 3e17;

struct state
{
    int len;
    ll dp[3][3];
} seg[400005], no = {0, {{-INF, -INF, -INF}, {-INF, -INF, -INF}, {-INF, -INF, -INF}}};

ll n, q, ord[100005], pos[100005], b[100005];
pll hw[100005];
pll w[100005];

ll match(int i, int j)
{
    return hw[i].F * w[j].F + (b[i] == j ? -INF : 0LL);
}

ll one(int i)
{
    return match(i, i);
}

ll two(int i)
{
    return match(i, i + 1) + match(i + 1, i);
}

ll three(int i)
{
    return max({match(i, i + 1) + match(i + 1, i + 2) + match(i + 2, i),
               match(i, i + 2) + match(i + 1, i) + match(i + 2, i + 1)});
}

state merge(state p, state q, int mid)
{
    state r = no;
    r.len = p.len + q.len;
    if (r.len == 2) // {1, 1}
        r.dp[0][2] = r.dp[2][0] = 0;
    if (q.len == 1) // {2, 1}
        for (int i = 0; i < 3; i++)
            r.dp[i][2] = max(r.dp[i][2], p.dp[i][1]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            r.dp[i][j] = max(r.dp[i][j], p.dp[i][0] + q.dp[0][j]);
            r.dp[i][j] = max(r.dp[i][j], p.dp[i][1] + q.dp[1][j] + two(mid));
            r.dp[i][j] = max(r.dp[i][j], p.dp[i][1] + q.dp[2][j] + three(mid));
            r.dp[i][j] = max(r.dp[i][j], p.dp[i][2] + q.dp[1][j] + three(mid - 1));
        }
    return r;
}

void modify(int pos, int i = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        seg[i] = no;
        seg[i].len = 1;
        seg[i].dp[0][0] = one(L);
        seg[i].dp[1][0] = seg[i].dp[0][1] = 0;
    }
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, i << 1, L, mid);
        else
            modify(pos, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1], mid);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> hw[i].F;
    for (int i = 1; i <= n; i++)
    {
        ord[i] = i;
        cin >> hw[i].S;
    }
    sort(ord + 1, ord + 1 + n, [&](int i, int j)
         { return hw[i] < hw[j]; });
    sort(hw + 1, hw + 1 + n);
    for (int i = 1; i <= n; i++)
        pos[ord[i]] = i, w[i] = pll(hw[i].S, i);
    sort(w + 1, w + 1 + n);

    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(w + 1, w + 1 + n, pll(hw[i].S, i)) - w;

    for (int i = 1; i <= n; i++)
        modify(i);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        swap(b[pos[x]], b[pos[y]]);
        modify(pos[x]), modify(pos[y]);
        cout << seg[1].dp[0][0] << '\n';
    }
}