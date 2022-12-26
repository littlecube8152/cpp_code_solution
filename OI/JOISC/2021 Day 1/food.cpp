#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, Q, t2[1000005], neg[1000005], pos[1000005], seg[1000005], lazy[1000005], ans[250005], color[250005];
vector<pair<int, pair<int, pll>>> modifies, colors;
vector<pair<int, pll>> queries;

void push(int i, ll val)
{
    if (val > 0)
        pos[i] += val;
    else if (val < 0)
    {
        if (pos[i] + val > 0)
            pos[i] += val;
        else
        {
            neg[i] += pos[i] + val;
            pos[i] = 0;
        }
    }
}

void t12(int mL, int mR, ll val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
    {
        if (val < 0)
            t2[i] += val;
        push(i, val);
    }
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i * 2, neg[i]);
        push(i * 2 + 1, neg[i]);
        push(i * 2, pos[i]);
        push(i * 2 + 1, pos[i]);
        pos[i] = neg[i] = 0;
        t12(mL, mR, val, i * 2, L, mid);
        t12(mL, mR, val, i * 2 + 1, mid + 1, R);
    }
}

pll query(int p, int i = 1, int L = 1, int R = N)
{
    if (L == R)
        return {neg[i], pos[i]};
    else
    {
        int mid = (L + R) / 2;
        push(i * 2, neg[i]);
        push(i * 2 + 1, neg[i]);
        push(i * 2, pos[i]);
        push(i * 2 + 1, pos[i]);
        pos[i] = neg[i] = 0;
        if (p <= mid)
            return query(p, i * 2, L, mid);
        else
            return query(p, i * 2 + 1, mid + 1, R);
    }
}

ll qt2(int p, int i = 1, int L = 1, int R = N)
{
    if (L == R)
        return t2[i];
    else
    {
        int mid = (L + R) / 2;
        push(i * 2, neg[i]);
        push(i * 2 + 1, neg[i]);
        push(i * 2, pos[i]);
        push(i * 2 + 1, pos[i]);
        pos[i] = neg[i] = 0;
        if (p <= mid)
            return t2[i] + qt2(p, i * 2, L, mid);
        else
            return t2[i] + qt2(p, i * 2 + 1, mid + 1, R);
    }
}

void modify(int mL, int mR, ll val, int i = 1, int L = 1, int R = Q + 1)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i * 2, L, mid);
        modify(mL, mR, val, i * 2 + 1, mid + 1, R);
        seg[i] = seg[i * 2 + 1] + lazy[i * 2 + 1];
    }
}

int bsearch(ll val, int i = 1, int L = 1, int R = Q + 1)
{
    if (L == R)
        return L;
    else
    {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        seg[i] += lazy[i];
        lazy[i] = 0;
        int mid = (L + R) / 2;
        if (seg[i * 2] + lazy[i * 2] >= val)
            return bsearch(val, i * 2, L, mid);
        else
            return bsearch(val, i * 2 + 1, mid + 1, R);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= Q; i++)
    {
        ll T, L, R, C, K;
        cin >> T >> L >> R;
        if (T == 1)
        {
            cin >> C >> K;
            t12(L, R, K);
            modifies.emplace_back(pair<int, pair<int, pll>>{L, {i, {C, K}}});
            modifies.emplace_back(pair<int, pair<int, pll>>{R + 1, {i, {-C, -K}}});
            color[i] = C;
            ans[i] = -1;
        }
        else if (T == 2)
        {
            cin >> K;
            t12(L, R, -K);
            ans[i] = -1;
        }
        else
        {
            pll cur = query(L);
            cur.F -= qt2(L);
            if (cur.S < R)
                ans[i] = 0;
            else
                queries.emplace_back(pair<int, pll>{L, {i, R + cur.F}});
        }
    }
    sort(modifies.begin(), modifies.end());
    sort(queries.begin(), queries.end());
    int mdx = 0, qdx = 0;
    for (int i = 1; i <= N; i++)
    {

        while (mdx < modifies.size() && modifies[mdx].F == i)
        {
            modify(modifies[mdx].S.F, Q + 1, modifies[mdx].S.S.S);
            mdx++;
        }
        while (qdx < queries.size() && queries[qdx].F == i)
        {
            int t = bsearch(queries[qdx].S.S);
            if (t > queries[qdx].S.F)
                ans[queries[qdx].S.F] = 0;
            else
                ans[queries[qdx].S.F] = color[t];
            qdx++;
        }
    }
    for (int i = 1; i <= Q; i++)
        if (ans[i] >= 0)
            cout << ans[i] << '\n';
}

/*
3 4 7
3 1 1000000000
1 1 3 1 5000000000
1 1 2 4 5000000000
3 2 5000000001
1 1 3 3 5000000000
3 3 10000000000
3 1 15000000000

4

*/