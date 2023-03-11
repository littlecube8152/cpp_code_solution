#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
ll mx[2000005], sum[2000005], lazy[2000005];
bool reset[2000005];

void apply(int i, int L, int R, bool re, ll val)
{
    if (re)
    {
        reset[i] = re, lazy[i] = val;
        sum[i] = val * (R - L + 1);
        mx[i] = val;
    }
    else
    {
        lazy[i] += val;
        sum[i] += val * (R - L + 1);
        mx[i] += val;
    }
}

void push(int i, int L, int R)
{
    int mid = (L + R) / 2;
    apply(i << 1, L, mid, reset[i], lazy[i]);
    apply(i << 1 | 1, mid + 1, R, reset[i], lazy[i]);
    lazy[i] = reset[i] = 0;
}

void modify(int mL, int mR, bool re, ll val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        apply(i, L, R, re, val);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        modify(mL, mR, re, val, i << 1, L, mid);
        modify(mL, mR, re, val, i << 1 | 1, mid + 1, R);
        sum[i] = sum[i << 1] + sum[i << 1 | 1], mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }
}

ll querySum(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return sum[i];
    else if (R < qL || qR < L)
        return 0;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        return querySum(qL, qR, i << 1, L, mid) + querySum(qL, qR, i << 1 | 1, mid + 1, R);
    }
}

ll queryMax(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return mx[i];
    else if (R < qL || qR < L)
        return 0;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        return max(queryMax(qL, qR, i << 1, L, mid), queryMax(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

void build(int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        cin >> mx[i];
        sum[i] = mx[i];
    }
    else
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
        sum[i] = sum[i << 1] + sum[i << 1 | 1], mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    build();
    for (int i = 1; i <= Q; i++)
    {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t <= 2)
            cin >> x;

        if (t == 1)
            modify(l, r, 1, x);
        else if (t == 2)
            modify(l, r, 0, x);
        else if (t == 3)
            cout << querySum(l, r) << '\n';
        else
            cout << queryMax(l, r) << '\n';
    }
}