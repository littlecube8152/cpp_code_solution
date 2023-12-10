#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct maxCons
{
    ll pre, suf, sum, res;
} seg[600005];

maxCons pull(maxCons l, maxCons r)
{
    return maxCons{max(l.pre, l.sum + r.pre),
                   max(l.suf + r.sum, r.suf),
                   l.sum + r.sum,
                   max(max(l.res, r.res), l.suf + r.pre)};
}

int N, Q;
ll C, w[150005];

void build(int i = 1, int L = 1, int R = N - 1)
{
    if (L == R)
        seg[i] = maxCons{max(0LL, w[L]),
                         max(0LL, w[L]),
                         w[L],
                         max(0LL, w[L])};
    else
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
        seg[i] = pull(seg[i << 1], seg[i << 1 | 1]);
    }
}

maxCons query(int qL, int qR, int i = 1, int L = 1, int R = N - 1)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (qR < L || R < qL)
        return maxCons{0, 0, 0, 0};
    else
    {
        int mid = (L + R) / 2;
        return pull(query(qL, qR, i << 1, L, mid),
                    query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q >> C;
    ll pre;
    cin >> pre;
    for (int i = 1; i < N; i++)
    {
        ll cur;
        cin >> cur;
        w[i] = 50 * (cur - pre);
        pre = cur;
    }
    for (int i = 1; i < N; i++)
    {
        ll p;
        cin >> p;
        w[i] -= p * C;
    }
    build();
    ll sum = 0;
    for (int i = 1; i <= Q; i++)
    {
        int l, r;
        cin >> l >> r;
        sum += query(l, r - 1).res;
    }
    cout << fixed << setprecision(10) << sum / 100.0 << '\n';
}