/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, C, A[100005], B[100005], P[200005], idx[200005];
vector<int> v[100005];
ll ans = 0;
pii seg[800005];
int lazy[800005];

pii getval(int i)
{
    return pii(seg[i].F + lazy[i], seg[i].S);
}

pii merge(pii L, pii R)
{
    pii res = pii(0, 0);
    res.F = max(L.F, R.F);
    if (L.F == res.F)
        res.S += L.S;
    if (R.F == res.F)
        res.S += R.S;
    return res;
}

void init(int i = 1, int L = 0, int R = 2 * N)
{
    seg[i] = pii(0, R - L + 1);
    lazy[i] = 0;
    if (L != R)
    {
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
    }
}

void modify(int mL, int mR, int val, int i = 1, int L = 0, int R = 2 * N)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(getval(i << 1), getval(i << 1 | 1));
    }
}

pii query(int qL, int qR, int i = 1, int L = 0, int R = 2 * N)
{
    if (qL <= L && R <= qR)
        return getval(i);
    else if (R < qL || qR < L)
        return pii(0, 0);
    else
    {
        int mid = (L + R) / 2;
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        seg[i] = merge(getval(i << 1), getval(i << 1 | 1));
        return merge(query(qL, qR, i << 1, L, mid),
                     query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}

void solve()
{
    ans = 0;
    cin >> N >> C;
    for (int i = 1; i <= C; i++)
        v[i].clear();
    init();
    for (int i = 1; i <= C; i++)
    {
        cin >> A[i] >> B[i];
        if(A[i] == 0 && B[i] == 0)
            A[i] = B[i] = 1e9;
        else if(A[i] == 0)
            A[i] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
        P[i + N] = P[i];
    }
    for (int i = 1; i <= 2 * N; i++)
    {
        idx[i] = v[P[i]].size();
        v[P[i]].emplace_back(i);
    }
    for (int i = 1; i <= C; i++)
    {
        modify(0, 2 * N, 1);

        if (v[i].size() >= 1)
            modify(v[i][0], 2 * N, -1);
        if (v[i].size() >= A[i])
            modify(v[i][A[i] - 1], 2 * N, 1);
        if (v[i].size() >= B[i] + 1)
            modify(v[i][B[i]], 2 * N, -1);
    }
    for (int i = 1; i <= N; i++)
    {
        pii p = query(i, i + N - 2);

        if (p.F == C)
            ans += p.S;

        int c = P[i];
        if (v[c].size() >= 1 + idx[i])
            modify(v[c][idx[i]], 2 * N, 1);
        if (v[c].size() >= A[c] + idx[i])
            modify(v[c][A[c] - 1 + idx[i]], 2 * N, -1);
        if (v[c].size() >= B[c] + idx[i] + 1)
            modify(v[c][B[c] + idx[i]], 2 * N, 1);

        if (v[c].size() >= 1 + idx[i] + 1)
            modify(v[c][1 + idx[i]], 2 * N, -1);
        if (v[c].size() >= A[c] + idx[i] + 1)
            modify(v[c][A[c] + idx[i]], 2 * N, 1);
        if (v[c].size() >= B[c] + idx[i] + 2)
            modify(v[c][B[c] + idx[i] + 1], 2 * N, -1);
    }
    for (int i = 1; i <= N; i++)
        if (A[P[i]] == 1)
            ans--;
    cout << ans << '\n';
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}

/*
3
3 2
0 1
0 1
1 1 2
5 2
0 1
0 2
1 2 1 2 2
3 3
0 2
0 2
2 2
1 1 3
*/
