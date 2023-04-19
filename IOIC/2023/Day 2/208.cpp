#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q;
ll seg[800005], lazy[800005];

ll getval(int i, ll L, ll R)
{
    return seg[i] + lazy[i] * (R - L + 1);
}

void modify(int mL, int mR, ll val, int i = 1, int L = 1, int R = n)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (mR < L || R < mL)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = getval(i << 1, L, mid) + getval(i << 1 | 1, mid + 1, R);
    }
}

ll query(int mL, int mR, int i = 1, int L = 1, int R = n)
{
    if (mL <= L && R <= mR)
        return getval(i, L, R);
    else if (mR < L || R < mL)
        return 0;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        seg[i] += lazy[i] * (R - L + 1);
        lazy[i] = 0;
        return query(mL, mR, i << 1, L, mid) +
               query(mL, mR, i << 1 | 1, mid + 1, R);
    }
}

signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        modify(i, i, a);
    }
    for (int i = 1; i <= q; i++)
    {
        ll t, l, r, d;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cin >> d;
            modify(l, r, d);
        }
        else
            cout << query(l, r) << '\n';
    }
}