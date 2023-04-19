#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M, Q, ddx;
pii pos[1500005];
vector<vector<int>> v = {{}};
vector<int> l = {0}, r = {0};
int sdx = 0;

int node()
{
    v.emplace_back(vector<int>{});
    l.emplace_back(0);
    r.emplace_back(0);
    ++sdx;
    return sdx;
}

void modify(int mL, int mR, int val, int i = 0, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        v[i].emplace_back(val);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        if (!l[i])
            l[i] = node();
        modify(mL, mR, val, l[i], L, mid);
        if (!r[i])
            r[i] = node();
        modify(mL, mR, val, r[i], mid + 1, R);
    }
}

void insert(int i)
{
    if (pos[i].F + pos[i].S == N)
        return;
    modify(pos[i].F + 1, N - pos[i].S, i);
}

vector<int> collect;
void query(int val, int i = 0, int L = 1, int R = N)
{
    for (auto j : v[i])
        collect.emplace_back(j);
    v[i].clear();
    if (L != R)
    {
        int mid = (L + R) / 2;
        if (val <= mid && l[i])
            query(val, l[i], L, mid);
        if (val > mid && r[i])
            query(val, r[i], mid + 1, R);
    }
}

void push(int L, bool isH)
{
    query((isH ? N - L : L + 1));
    for (auto i : collect)
        if (isH && pos[i].F < N - L && pos[i].S <= L)
        {
            pos[i].F = N - L;
            insert(i);
        }
        else if (!isH && pos[i].F <= L && pos[i].S < N - L)
        {
            pos[i].S = N - L;
            insert(i);
        }
    collect.clear();
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
        insert(ddx);
    }
    for (int i = 1; i <= Q; i++)
    {
        int T, L, P, X, Y;
        cin >> T;
        if (T == 1)
        {
            cin >> P;
            cout << pos[P].F << ' ' << pos[P].S << '\n';
        }
        else if (T == 2)
        {
            cin >> L;
            push(L, 1);
        }
        else if (T == 3)
        {
            cin >> L;
            push(L, 0);
        }
        else
        {
            cin >> X >> Y;
            ddx++;
            pos[ddx] = pii(X, Y);
            insert(ddx);
        }
    }
}