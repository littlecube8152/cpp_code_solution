#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

#define matrix vector<vector<ll>>
const ll mod = 998244353;

matrix operator*(matrix A, matrix B)
{
    int n = 6;
    matrix C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

// sum AC*(A+1) = sum AC*A + sum AC
// sum (AC+A)*A = sum AC*A + sum A*A
//           1  A AC AAC AA ACAC
matrix A = {{1, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {1, 2, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1}},
       C = {{1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 2, 1, 1}},
       AC(6, vector<ll>(6, 0));

matrix seg[100005];
ll N, Q, a, b, c;

void modify(int pos, matrix &m, int i = 1, int L = 1, int R = N)
{
    if (L == R)
        seg[i] = m;
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, m, i + 1, L, mid);
        else
            modify(pos, m, i + (mid - L + 1) * 2, mid + 1, R);
        seg[i] = seg[i + (mid - L + 1) * 2] * seg[i + 1];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            AC[i][j] = A[i][j] + C[i][j];
    cin >> N >> Q >> a >> b >> c;
    for (int i = 1; i <= 2 * N; i++)
        seg[i] = matrix(6, vector<ll>(6, 0));
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
            modify(i, A);
        else if (c == 'C')
            modify(i, C);
        else
            modify(i, AC);
    }
    cout << (a * seg[1][5][0] + b * seg[1][2][0] + c * seg[1][0][0]) % mod << '\n';
    for (int i = 1; i <= Q; i++)
    {
        int p;
        char cr;
        cin >> p >> cr;
        if (cr == 'A')
            modify(p, A);
        else if (cr == 'C')
            modify(p, C);
        else
            modify(p, AC);
        cout << (a * seg[1][5][0] + b * seg[1][2][0] + c * seg[1][0][0]) % mod << '\n';
    }
}