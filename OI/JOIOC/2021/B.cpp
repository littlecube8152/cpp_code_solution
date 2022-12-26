#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct mxSum
{
    int l = 0, m = 0, r = 0, len = 0;
};

mxSum merge(mxSum L, mxSum R)
{
    return mxSum{L.l == L.len ? L.l + R.l : L.l, max({L.m, R.m, L.r + R.l}), R.r == R.len ? R.r + L.r : R.r, L.len + R.len};
}

int N, D, A[300005], dp[300005];

struct mxSumSeg
{
    mxSum seg[1200005];
    bool lazy[1200005];

    void modify(int pos, bool val, int i = 1, int L = 1, int R = N)
    {
        if (L == R)
            seg[i] = (val ? mxSum{1, 1, 1, 1} : mxSum{0, 0, 0, 1});
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1, L, mid);
            else
                modify(pos, val, i << 1 | 1, mid + 1, R);
            seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        }
    }


    void hide(int mL, int mR, int i = 1, int L = 1, int R = N)
    {
        if (mL <= L && R <= mR)
            lazy[i] ^= 1;
        else if (R < mL || mR < L)
            return;
        else
        {
            int mid = (L + R) / 2;
            hide(mL, mR, i << 1, L, mid);
            hide(mL, mR, i << 1 | 1, mid + 1, R);
            seg[i] = merge(lazy[i << 1] ? mxSum{0, 0, 0, 0} : seg[i << 1], lazy[i << 1 | 1] ? mxSum{0, 0, 0, 0} : seg[i << 1 | 1]);
        }
    }

    mxSum query(int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (lazy[i] || R < qL || qR < L)
            return mxSum{0, 0, 0, 0};
        else if (qL <= L && R <= qR)
            return seg[i];
        else
        {
            int mid = (L + R) / 2;
            return merge(query(qL, qR, i << 1, L, mid),
                         query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} sumSeg;

struct mxSeg
{
    int seg[1200005];

    void modify(int pos, int val, int i = 1, int L = 1, int R = N)
    {
        if (L == R)
            seg[i] = val;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1, L, mid);
            else
                modify(pos, val, i << 1 | 1, mid + 1, R);
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    int query(int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (R < qL || qR < L)
            return 0;
        else if (qL <= L && R <= qR)
            return seg[i];
        else
        {
            int mid = (L + R) / 2;
            return max(query(qL, qR, i << 1, L, mid),
                       query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} maxSeg;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> D;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    vector<int> v;
    for (int i = 1; i <= N; i++)
        v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i, int j)
         { return pii(A[i], -i) < pii(A[j], -j); });

    for (int i = 1; i <= N; i++)
        sumSeg.modify(i, 1);

    for (int i : v)
    {
        int L = 1, R = i - 1;
        sumSeg.hide(i, N);
        while(L < R)
        {
            int mid = (L + R) / 2;
            if(sumSeg.query(mid + 1, N).m >= D)
                L = mid + 1;
            else
                R = mid;
        }
        sumSeg.hide(i, N);
        dp[i] = maxSeg.query(L, i - 1) + 1;
        maxSeg.modify(i, dp[i]);
        sumSeg.modify(i, 0);
    }
    cout << maxSeg.query(1, N) << '\n';
}