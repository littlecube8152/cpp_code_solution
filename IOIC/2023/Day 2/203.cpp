#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>
using namespace std;

ll n, m, q;
const int k = 256, P = 8;
// j * 16^i
matrix B[P][k];
int f[20];
const ll mod = 998244353, prob = 299473306;
string s;

void mmul(matrix A, matrix B, matrix &C)
{
    for (int i = 0; i <= m; i++)
        for (int k = 0; k <= m; k++)
            for (int j = 0; j <= m; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
}

void rmul(vector<ll> A, matrix B, vector<ll> &C)
{
    for (int i = 0; i <= m; i++)
        C[i] = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            C[j] = (C[j] + A[i] * B[i][j]) % mod;
}

void mpow(ll p, vector<ll> &A)
{
    for (int i = 0; i < P; i++)
    {
        if (p & (k - 1))
            rmul(A, B[i][p & (k - 1)], A);
        p /= k;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> s >> q;

    for (int i = 0; i < P; i++)
        for (int j = 0; j < k; j++)
            B[i][j] = (matrix(m + 1, vector<ll>(m + 1, 0)));

    f[0] = -1;
    for (int i = 1, cur = -1; i <= m; i++)
    {
        while (cur >= 0)
            if (s[i - 1] == s[cur])
                break;
            else
                cur = f[cur];
        f[i] = ++cur;
    }

    B[0][1][m][m] = 1;
    for (int i = 0; i < m; i++)
        for (char j = '0'; j <= '9'; j++)
        {
            int cur = i;
            while (cur >= 0)
                if (s[cur] == j)
                    break;
                else
                    cur = f[cur];
            B[0][1][i][cur + 1] = (B[0][1][i][cur + 1] + prob) % mod;
        }

    for (int i = 0; i < P; i++)
    {
        if (i > 0)
            mmul(B[i - 1][k - 1], B[i - 1][1], B[i][1]);
        for (int j = 2; j < k; j++)
            mmul(B[i][j - 1], B[i][1], B[i][j]);
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> n;
        vector<ll> A(m + 1, 0);
        A[0] = 1;
        mpow(n, A);
        cout << A[m] << '\n';
    }
}