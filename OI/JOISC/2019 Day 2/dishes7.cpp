#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const ll inf = 1'000'000'000'000'000'000;
const ll mxN = 2'000'006;
int N, M;
ll A[mxN], B[mxN], S[mxN], T[mxN], P[mxN], Q[mxN], dp[mxN], seg[4 * mxN], lazy[4 * mxN], bit[mxN], rcost[mxN], ucost[mxN], tmp[mxN][2];
int rangeA[mxN], rangeB[mxN], nrange[mxN];
bool vis[mxN];
vector<pii> ins[mxN];

void Bmodify(int pos, ll val)
{
    for (int i = pos; i < mxN; i += (i & -i))
        bit[i] += val;
}

ll Bquery(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void init(int i = 1, int L = 0, int R = N)
{
    if (L == R)
        seg[i] = -inf, lazy[i] = 0;
    if (L != R)
    {
        int mid = (L + R) / 2;
        init(i << 1, L, mid);
        init(i << 1 | 1, mid + 1, R);
    }
}

void modify(int mL, int mR, ll val, int i = 1, int L = 0, int R = N)
{
    if (mL <= L && R <= mR)
        seg[i] += val, lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        seg[i << 1] += lazy[i], seg[i << 1 | 1] += lazy[i];
        lazy[i << 1] += lazy[i], lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
    }
}

ll query(int mL, int mR, int i = 1, int L = 0, int R = N)
{
    if (mL <= L && R <= mR)
        return seg[i];
    else if (R < mL || mR < L)
        return -inf;
    else
    {
        int mid = (L + R) / 2;
        seg[i << 1] += lazy[i], seg[i << 1 | 1] += lazy[i];
        lazy[i << 1] += lazy[i], lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
        return max(query(mL, mR, i << 1, L, mid),
                   query(mL, mR, i << 1 | 1, mid + 1, R));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> S[i] >> P[i];
        A[i] += A[i - 1];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i] >> T[i] >> Q[i];
        B[i] += B[i - 1];
    }
    for (int i = 1; i <= N; i++)
    {
        rangeA[i] = upper_bound(B, B + 1 + M, S[i] - A[i]) - B - 1;
        if (rangeA[i] == -1)
            rangeA[i] = 0, P[i] = 0;
    }

    for (int i = 1; i <= M; i++)
    {
        rangeB[i] = upper_bound(A, A + 1 + N, T[i] - B[i]) - A - 1;
        if (rangeB[i] == -1)
            rangeB[i] = 0, Q[i] = 0;

        if (rangeB[i] < N)
        { // cerr << "build insert " << i << " -> " << rangeB[i] + 1 << '\n';
            ins[rangeB[i] + 1].emplace_back(pii(i - 1, i));
            if (rangeA[rangeB[i] + 1] == i - 1)
                vis[rangeB[i] + 1] = 1;
        }
        else
            rangeB[i] = -1;
    }
    rangeA[++N] = M;
    for (int i = 1; i <= N; i++)
        if (!vis[i])
            ins[i].emplace_back(pii(rangeA[i], -1));
    for (int i = 1; i <= N; i++)
        tmp[i][0] = P[i], tmp[i][1] = rangeA[i];
    int nN = 0;

    for (int i = 1; i <= N; i++)
    {
        sort(ins[i].begin(), ins[i].end(), greater<>());
        for (auto [j, k] : ins[i])
        {
            ++nN;
            rangeA[nN] = j;
            P[nN] = 0;
            if (j == tmp[i][1])
            {
                P[nN] = tmp[i][0];
                rangeA[nN] = tmp[i][1];
                nrange[i] = nN;
            }
            if (k > 0)
                rangeB[k] = nN - 1;
        }
    }
    N = nN;
    for (int i = 1; i <= M; i++)
        if(rangeB[i] == -1)
            rangeB[i] = N;

    vector<int> v;

    for (int i = 1; i <= N; i++)
        v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i, int j)
         { return make_pair(rangeA[i], -i) < make_pair(rangeA[j], -j); });

    ll sumR = 0;
    for (int i = N; i >= 1; i--)
    {
        rcost[i] = sumR - Bquery(rangeA[i] + 1);
        sumR += P[i];
        Bmodify(rangeA[i] + 1, P[i]);
    }
    for (int i = 0; i < mxN; i++)
        bit[i] = 0;

    int last = 1;
    ll sumU = 0;

    init();
    modify(0, 0, inf);
    for (int i = 1; i <= N; i++)
        modify(0, i - 1, P[i]);
    for (int i : v)
    {
        while (last <= rangeA[i] && last <= M)
        {
            sumU += Q[last];
            Bmodify(rangeB[last] + 1, Q[last]);
            modify(0, rangeB[last], Q[last]);
            last++;
        }
        ucost[i] = sumU - Bquery(i);
        dp[i] = query(0, i - 1) - rcost[i];
        // cerr << i << ' ' << rangeA[i] << ' ' << query(0, i - 1) << " - " << rcost[i] << '\n';
        modify(0, i - 1, -P[i]);
        modify(i, i, inf + dp[i] - ucost[i]);
    }
    cout << dp[N] << '\n';
}

/*
1 2
1 0 0
1 0 0
1 5 -1

3 3
1 1 1
1 3 -5
1 4 -2
1 1 2
1 3 -1
1 4 -2

2 2
1 1 5
1 10 -10
1 0 0
1 3 6

2 2
*/