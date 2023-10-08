#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

ll A(int i, int j);

int opt[1000006];
ll best[1000006];
void smawk(vector<int> &r, vector<int> &c);
void interpolate(vector<int> &r, vector<int> &c)
{
    int n = (int)r.size();
    vector<int> er;
    er.reserve(n);
    for (int i = 1; i < n; i += 2)
        er.emplace_back(r[i]);
    smawk(er, c);
    for (int i = 0, j = 0; j < c.size(); j++)
    {
        ll cur = A(r[i], c[j]);
        if (cur < best[r[i]])
            opt[r[i]] = c[j], best[r[i]] = cur;
        if (i + 2 < n && c[j] == opt[r[i + 1]])
            j--, i += 2;
    }
}
void reduce(vector<int> &r, vector<int> &c)
{
    int n = (int)r.size();
    vector<int> nc;
    nc.reserve(n);
    for (int i : c)
    {
        int j = (int)nc.size();
        while (j && A(r[j - 1], nc[j - 1]) > A(r[j - 1], i))
            nc.pop_back(), j--;
        if (nc.size() < n)
            nc.emplace_back(i);
    }
    smawk(r, nc);
}
void smawk(vector<int> &r, vector<int> &c)
{
    if (r.size() == 1 && c.size() == 1)
        opt[r[0]] = c[0], best[r[0]] = A(r[0], c[0]);
    else if (r.size() >= c.size())
        interpolate(r, c);
    else
        reduce(r, c);
}

int N, K, pos[1000006], last;
pll a[2000006];
ll seg[30000007];
int cnt[27000007], l[27000007], r[27000007], t[27000007], root[1000006];

void build(int i, int L = 1, int R = N + K)
{
    t[i] = 0;
    if (L == R)
    {
        if (a[L].S == 0)
            cnt[i] = 1, seg[i] = a[L].F;
        else
            cnt[i] = seg[i] = 0, pos[a[L].S] = L;
    }
    else
    {
        int mid = (L + R) / 2;
        l[i] = ++last;
        build(l[i], L, mid);
        r[i] = ++last;
        build(r[i], mid + 1, R);
        seg[i] = seg[l[i]] + seg[r[i]];
        cnt[i] = cnt[l[i]] + cnt[r[i]];
    }
}

int copy(int i, int T)
{
    ++last;
    seg[last] = seg[i];
    cnt[last] = cnt[i];
    l[last] = l[i];
    r[last] = r[i];
    t[last] = T;
    return last;
}

void modify(int pos, int T, int i, int L = 1, int R = N + K)
{
    if (L == R)
        cnt[i] = 1, seg[i] = a[L].F;
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, T, l[i] = copy(l[i], T), L, mid);
        else
            modify(pos, T, r[i] = copy(r[i], T), mid + 1, R);
        seg[i] = seg[l[i]] + seg[r[i]];
        cnt[i] = cnt[l[i]] + cnt[r[i]];
    }
}

// search on t2 - t1
ll bsearch(int remain, int i1, int i2, int i = 0)
{
    if (remain == 0)
        return 0;
    if (remain >= cnt[l[i2]] - cnt[l[i1]] + cnt[l[i]])
        return seg[l[i2]] - seg[l[i1]] + seg[l[i]] + bsearch(remain - (cnt[l[i2]] - cnt[l[i1]] + cnt[l[i]]), r[i1], r[i2], r[i]);
    else
        return bsearch(remain, l[i1], l[i2], l[i]);
}

ll A(int i, int j)
{
    if (j < i)
        return (ll)1e18 + i - j;
    else
        return bsearch(j - i + 1, root[i - 1], root[j]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    // mt19937 rd(2);
    while (T--)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> a[i].F;
        for (int i = 1; i <= K; i++)
            cin >> a[i + N].F;

        for (int i = 1; i <= N + K; i++)
        {
            if (i <= N)
                a[i].S = i;
            else
                a[i].S = 0;
            a[i].F = -a[i].F;
        }
        sort(a + 1, a + 1 + N + K);
        build(root[0] = last = 0);
        for (int i = 1; i <= N; i++)
            modify(pos[i], i, root[i] = copy(root[i - 1], i));

        for (int i = 1; i <= N; i++)
            opt[i] = 0, best[i] = 2e18;
        vector<int> r, c;
        for (int i = 1; i <= N; i++)
            r.emplace_back(i);
        for (int i = 1; i <= N; i++)
            c.emplace_back(i);
        smawk(r, c);
        ll ans = 1e18;
        for (int i = 1; i <= N; i++)
            ans = min(ans, best[i]);
        cout << -ans << '\n';
    }
}
