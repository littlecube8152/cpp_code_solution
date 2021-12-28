#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct segTree
{
    int l[100000], r[100000], seg[100000], rdx = 1;
    const ll mxL = -10, mxR = 1000000010;
    void modify(ll L, ll R, int i, int idx, int val)
    {
        if (L == R)
        {
            seg[i] = val;
            return;
        }
        int mid = (L + R) / 2;
        if (idx <= mid)
        {
            if (l[i] == 0)
                l[i] = ++rdx;
            modify(L, mid, l[i], idx, val);
        }
        else
        {
            if (r[i] == 0)
                r[i] = ++idx;
            modify(mid + 1, R, r[i], idx, val);
        }
        seg[i] = max((l[i] == 0 ? 0 : seg[l[i]]), (r[i] == 0 ? 0 : seg[r[i]]));
    }

    void modify(int idx, int val)
    {
        modify(mxL, mxR, 1, idx, val);
    }

    int query(ll L, ll R, int i, ll qL, ll qR)
    {
        if (qL <= L && R <= qR)
            return seg[i];
        if (qR < L || R < qL)
            return 0;
        int mid = (L + R) / 2;
        return max((l[i] == 0 ? 0 : query(L, mid, l[i], qL, qR)), (r[i] == 0 ? 0 : query(mid + 1, R, r[i], qL, qR)));
    }

    int query(ll qR)
    {
        return query(mxL, mxR, 1, mxL, qR);
    }
};

ll N, x;
segTree nmod, mod[11], moded;
ll nmoddp[200005], moddp[200005][12], modeddp[200005];

signed main()
{
    
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> x;
    for (int i = 1; i <= N; i++)
    {
        ll k;
        cin >> k;
        for (int j = 1; j <= x; j++)
            modeddp[i] = max(modeddp[i], mod[j].query(k - 1)) + 1;
        for (int j = 1; j <= x; j++)
            modeddp[i] = max(modeddp[i], mod[5 + j].query(k - 1)) + 1;
        modeddp[i] = max(modeddp[i], moded.query(k - 1)) + 1;

        moded.modify(k, modeddp[i]);

        for (int j = 1; j <= x; j++)
        {
            moddp[i][j] = max(nmod.query(k - 1 - j), mod[j].query(k - 1 - j)) + 1;
            mod[j].modify(k - j, moddp[i][j]);
        }
        for (int j = 1; j <= x; j++)
        {
            moddp[i][j + 5] = max(nmod.query(k - 1 + j), mod[j].query(k - 1 + j)) + 1;
            mod[j].modify(k + j, moddp[i][j]);
        }

        nmoddp[i] = nmod.query(k - 1) + 1;
        nmod.modify(k, nmoddp[i]);
    }
    int ans = 0;
    ans = max(ans, nmod.query(1000000010));
    ans = max(ans, moded.query(1000000010));
    for (int i = 1; i <= x; i++)
        ans = max({ans, mod[i].query(1000000010), mod[i + 5].query(1000000010)});
    cout << ans << '\n';
}
