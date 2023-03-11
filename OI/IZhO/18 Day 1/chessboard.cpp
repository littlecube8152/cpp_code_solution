#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, l[100005], d[100005], r[100005], u[100005];
ll ans;

pll operator+(pll p1, pll p2)
{
    return pll(p1.F + p2.F, p1.S + p2.S);
}

bool isB(int x, int y, int M)
{
    return (x / M + y / M) % 2;
}

pll calcCorner(ll L, ll R, ll D, ll U, int M)
{
    if (isB(L, D, M))
        return pll((R - L) * (U - D), 0);
    else
        return pll(0, (R - L) * (U - D));
}

pll calcColumn(ll L, ll R, ll D, ll U, int M)
{
    pll res;
    ll blocks = (U - D) / M;
    if (blocks % 2 == 1)
        res = pll((R - L) * (blocks / 2 + 1) * M, (R - L) * (blocks / 2) * M);
    else
        res = pll((R - L) * (blocks / 2) * M, (R - L) * (blocks / 2) * M);
    if (!isB(L, D, M) && blocks % 2 == 1)
        swap(res.F, res.S);
    return res;
}

pll calcBlock(ll L, ll R, ll D, ll U, ll M)
{
    pll res;
    ll blocks = (R - L) * (U - D) / M / M;
    if (blocks % 2 == 1)
        res = pll(M * M * (blocks / 2 + 1), M * M * (blocks / 2));
    else
        res = pll(M * M * (blocks / 2), M * M * (blocks / 2));
    if (!isB(L, D, M) && blocks % 2 == 1)
        swap(res.F, res.S);
    return res;
}

void solve(int M)
{
    pll res = pll(0, 0), board = calcBlock(0, N, 0, N, M);
    for (int i = 1; i <= K; i++)
    {
        ll mL = (l[i] + M - 1) / M * M,
           mR = r[i] / M * M,
           mD = (d[i] + M - 1) / M * M,
           mU = u[i] / M * M;
        pll cur;
        if (mL > mR && mD > mU)
            cur = calcCorner(l[i], r[i], d[i], u[i], M);
        else if (mL > mR)
            cur = calcCorner(l[i], r[i], d[i], mD, M) +
                  calcColumn(l[i], r[i], mD, mU, M) +
                  calcCorner(l[i], r[i], mU, u[i], M);
        else if (mD > mU)
            cur = calcCorner(l[i], mL, d[i], u[i], M) +
                  calcColumn(d[i], u[i], mL, mR, M) +
                  calcCorner(mR, r[i], d[i], u[i], M);
        else
            cur = calcCorner(l[i], mL, d[i], mD, M) + calcColumn(d[i], mD, mL, mR, M) + calcCorner(mR, r[i], d[i], mD, M) +
                  calcColumn(l[i], mL, mD, mU, M) + calcBlock(mL, mR, mD, mU, M) + calcColumn(mR, r[i], mD, mU, M) +
                  calcCorner(l[i], mL, mU, u[i], M) + calcColumn(mU, u[i], mL, mR, M) + calcCorner(mR, r[i], mU, u[i], M);
        res = res + cur;
    }
    // cerr << M << ' ' << board.F << ' ' << board.S << '\n';
    ans = min({ans, board.F - res.F + res.S, res.F + board.S - res.S});
}

signed main()
{
    cin >> N >> K;
    ans = N * N;
    for (int i = 1; i <= K; i++)
    {
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        l[i]--, d[i]--;
    }
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            solve(i);
    cout << ans << '\n';
}

/*
6 8
3 3 3 3
1 2 1 2
3 4 3 4
5 5 5 5
4 3 4 3
4 4 4 4
2 1 2 1
3 6 3 6
*/