#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, arr[150005], L, R, idx, ans, lazy[600005];
pii seg[600005];
vector<int> cnt[150005];
map<int, int> mp;

void build(int i = 1, int L = 1, int R = N)
{
    seg[i] = {0, R - L + 1};
    if (L < R)
    {
        int mid = (L + R) / 2;
        build(i * 2, L, mid);
        build(i * 2 + 1, mid + 1, R);
    }
}

pii getval(int i)
{
    return pii{seg[i].F + lazy[i], seg[i].S};
}

void debug(int i = 1, int L = 1, int R = N)
{
}

pii merge(pii p1, pii p2)
{
    if (p1.F == p2.F)
        return pii{p1.F, p1.S + p2.S};
    else
        return min(p1, p2);
}

void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = N)
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
        seg[i] = merge(getval(i * 2), getval(i * 2 + 1));
    }
}

pii query(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return getval(i);
    else if (R < qL || qR < L)
        return {1e9, 0};
    else
    {
        int mid = (L + R) / 2;
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;
        pii res = merge(query(qL, qR, i * 2, L, mid), query(qL, qR, i * 2 + 1, mid + 1, R));
        seg[i] = merge(getval(i * 2), getval(i * 2 + 1));
        return res;
    }
}

signed main()
{
    cin >> N >> L >> R;
    build();
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if (mp[arr[i]] == 0)
            mp[arr[i]] = ++idx;
        arr[i] = mp[arr[i]];
    }
    for (int i = N; i >= 1; i--)
    {
        if (cnt[arr[i]].size() >= 1)
            modify(cnt[arr[i]][cnt[arr[i]].size() - 1], N, -1);
        if (cnt[arr[i]].size() >= 2)
            modify(cnt[arr[i]][cnt[arr[i]].size() - 2], N, 1);
        cnt[arr[i]].emplace_back(i);
        if (cnt[arr[i]].size() >= 1)
            modify(cnt[arr[i]][cnt[arr[i]].size() - 1], N, 1);
        if (cnt[arr[i]].size() >= 2)
            modify(cnt[arr[i]][cnt[arr[i]].size() - 2], N, -1);
        pii res = query(i, N);
        if (res.F == 0)
            ans += res.S;
    }
    cout << ans << '\n';
}