#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int M, N, Q, seg[400005], lazy[400005], k[100005];
pii range[100005], ans[100005];
pair<pii, int> qu[100005];

void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        lazy[i] += val, seg[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i], seg[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i], seg[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
    }
}

int query(int mL, int mR, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        return seg[i];
    else if (R < mL || mR < L)
        return 0;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i], seg[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i], seg[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        return max(query(mL, mR, i << 1, L, mid),
                   query(mL, mR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    vector<pii> bs, nxt;
    for (int i = 1; i <= M; i++)
    {
        cin >> range[i].F >> range[i].S >> k[i];
        ans[i] = pii(1, Q + 1);
        bs.emplace_back(pii((ans[i].F + ans[i].S) / 2, i));
    }
    for (int i = 1; i <= Q; i++)
        cin >> qu[i].F.F >> qu[i].F.S >> qu[i].S;

    for (int t = 1; t <= 20; t++)
    {
        for (int i = 1; i <= 4 * N; i++)
            seg[i] = lazy[i] = 0;

        int bdx = 0;
        for (int i = 1; i <= Q + 1; i++)
        {
            if (i <= Q)
                modify(qu[i].F.F, qu[i].F.S, qu[i].S);
            vector<int> suc, fail;
            while (bdx < M && bs[bdx].F == i)
            {
                auto [mid, j] = bs[bdx];
                if (query(range[j].F, range[j].S) >= k[j])
                    suc.emplace_back(j);
                else
                    fail.emplace_back(j);
                bdx++;
            }
            for (auto j : suc)
            {
                ans[j].S = i;
                nxt.emplace_back(pii((ans[j].F + ans[j].S) / 2, j));
            }
            for (auto j : fail)
            {
                ans[j].F = i + 1;
                nxt.emplace_back(pii((ans[j].F + ans[j].S) / 2, j));
            }
        }
        swap(bs, nxt);
        nxt.clear();
    }
    for (int i = 1; i <= M; i++)
        cout << (ans[i].F > Q ? -1 : ans[i].F) << " \n"[i == M];
}