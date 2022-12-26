#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct query
{
    int i, T, L, R;
};

struct SegTree
{
    const static int N = 400005;
    ll seg[4 * N + 5], lazy[4 * N + 5];
    void modify(int pos, ll val, int i = 1, int L = 1, int R = N)
    {
        if (pos <= L)
            lazy[i] += val;
        else if (R < pos)
            return;
        else
        {
            int mid = (L + R) / 2;
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
            modify(pos, val, i * 2, L, mid);
            modify(pos, val, i * 2 + 1, mid + 1, R);
            seg[i] = seg[i * 2] + lazy[i * 2] * (mid - L + 1) +
                     seg[i * 2 + 1] + lazy[i * 2 + 1] * (R - mid);
        }
    }
    ll query(int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (qL <= L && R <= qR)
            return seg[i] + (R - L + 1) * lazy[i];
        else if (R < qL || qR < L)
            return 0;
        else
        {
            int mid = (L + R) / 2;
            seg[i] += (R - L + 1) * lazy[i];
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
            return query(qL, qR, i * 2, L, mid) + query(qL, qR, i * 2 + 1, mid + 1, R);
        }
    }
};

ll N, Q, arr[200005], ans[200005], front[200005], back[200005];
SegTree reg, off;
query q[200005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= Q; i++)
    {
        cin >> q[i].T >> q[i].L >> q[i].R;
        q[i].i = i;
    }
    sort(q + 1, q + 1 + Q, [](query q1, query q2)
         { return q1.T < q2.T; });

    int qdx = 1, odx = 0, rdx = 0;
    vector<pair<int, pll>> offmodifies, regularmodifies;
    vector<int> mono;

    auto triangle = [&](int x, int y, ll val)
    {
        regularmodifies.emplace_back(pair<int, pll>{y, {x, val}});
        offmodifies.emplace_back(pair<int, pll>{y, {x + N - y, -val}});
    };

    for (int i = 1; i <= N; i++)
        triangle(i, 0, arr[i]);

    mono.clear();
    for (int i = 1; i <= N; i++)
    {
        while (!mono.empty() && arr[mono.back()] < arr[i])
            mono.pop_back();
        if (!mono.empty())
        {
            triangle(i, i - mono.back(), -arr[i]);
            front[i] = mono.back();
        }
        mono.emplace_back(i);
    }

    mono.clear();
    for (int i = N; i >= 1; i--)
    {
        while (!mono.empty() && arr[mono.back()] <= arr[i])
            mono.pop_back();
        if (!mono.empty())
        {
            triangle(mono.back(), mono.back() - i, -arr[i]);
            back[i] = mono.back();
        }
        mono.emplace_back(i);
    }

    for (int i = 1; i <= N; i++)
        if (front[i] && back[i])
            triangle(back[i], back[i] - front[i], arr[i]);
    sort(regularmodifies.begin(), regularmodifies.end());
    sort(offmodifies.begin(), offmodifies.end());

    for (int i = 0; i <= N; i++)
    {
        while (rdx < regularmodifies.size() && regularmodifies[rdx].F == i)
        {
            reg.modify(regularmodifies[rdx].S.F, regularmodifies[rdx].S.S);
            rdx++;
        }
        while (odx < offmodifies.size() && offmodifies[odx].F == i)
        {
            off.modify(offmodifies[odx].S.F, offmodifies[odx].S.S);
            odx++;
        }

        while (qdx <= Q && q[qdx].T == i)
        {
            ans[q[qdx].i] = reg.query(q[qdx].L, q[qdx].R) + off.query(N - i - 1 + q[qdx].L, N - i - 1 + q[qdx].R);
            qdx++;
        }
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}

/*
4 1 1
4 2 2
4 3 3
4 4 4
4 5 5
*/