#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M, Q, ddx;
pii pos[1500005];
vector<vector<int>> v = {{(int)1e9}};
vector<int> l = {0}, r = {0};
int sdx = 0;

int node()
{
    v.emplace_back(vector<int>{(int)1e9});
    l.emplace_back(0);
    r.emplace_back(0);
    ++sdx;
    return sdx;
}

int query(int mL, int mR, int i = 0, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        return v[i].back();
    else if (R < mL || mR < L)
        return (int)1e9;
    else
    {
        int mid = (L + R) / 2;
        return min(l[i] ? query(mL, mR, l[i], L, mid) : (int)1e9,
                   r[i] ? query(mL, mR, r[i], mid + 1, R) : int(1e9));
    }
}

void modify(int val, int i = 0, int L = 1, int R = N)
{
    v[i].back() = min(v[i].back(), val);
    if (L != R)
    {
        int mid = (L + R) / 2;
        if (val <= mid)
        {
            if (!l[i])
                l[i] = node();
            modify(val, l[i], L, mid);
        }
        if (val > mid)
        {
            modify(val, r[i], mid + 1, R);
            if (!r[i])
                r[i] = node();
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++)
    {
        ddx++;
        cin >> pos[ddx].F >> pos[ddx].S;
    }
    for (int i = 1; i <= Q; i++)
    {
        int T, L, P, X, Y;
        cin >> T;
        if (T == 1)
        {
            cin >> P;
            cout << max(pos[P].F, query(pos[P].F + 1, N - pos[P].S)) << ' ' << pos[P].S << '\n';
        }
        else if (T == 2)
        {
            cin >> L;
            modify(N - L);
        }
        else if (T == 3)
        {
            assert(0);
        }
        else
        {
            cin >> X >> Y;
            ddx++;
            pos[ddx] = pii(X, Y);
        }
    }
}