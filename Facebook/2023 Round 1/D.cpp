/*
    Remember to turn off all debug flags!
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1'000'000'007;
int T, N, Q;
int A[1000049], lazy[4000049];
pii mn[4000049], mx[4000049];

void pull(int i)
{
    mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
    mx[i << 1].S *= -1, mx[i << 1 | 1].S *= -1;
    mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    mx[i].S *= -1, mx[i << 1].S *= -1, mx[i << 1 | 1].S *= -1;
}

void build(int i = 1, int L = 1, int R = N)
{
    lazy[i] = 0;
    if (L == R)
        mn[i] = mx[i] = pii(A[L], L);
    else
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
        pull(i);
    }
}

void apply(int i)
{
    lazy[i] ^= 1;
    swap(mn[i], mx[i]);
    mn[i].F = mod - mn[i].F;
    mx[i].F = mod - mx[i].F;
}

void modify(int mL, int mR, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        apply(i);
    else if (R < mL || mR < L)
        return;
    else
    {
        if (lazy[i])
            lazy[i] = 0, apply(i << 1), apply(i << 1 | 1);

        int mid = (L + R) / 2;
        modify(mL, mR, i << 1, L, mid);
        modify(mL, mR, i << 1 | 1, mid + 1, R);
        pull(i);
    }
}

signed main()
{
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        ll sum = 0;
        build();
        cin >> Q;
        for (int i = 1; i <= Q; i++)
        {
            int L, R;
            cin >> L >> R;
            modify(L, R);
            sum += mx[1].S;
        }
        cout << "Case #" << t << ": " << sum << '\n';
    }
}
