#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

using mtx = vector<vector<int>>;

const int mod = 10'007;
int n, m, dp[205][205][205], a[205], b[105], c[105], t;
string s;

mtx mul(mtx A, mtx B)
{
    mtx C(A.size(), vector<int>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
        for (int j = i; j < A.size(); j++)
            for (int k = i; k <= j; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

mtx fpow(mtx B, int p)
{
    mtx A = B;
    p--;
    while (p)
    {
        if (p & 1)
            A = mul(A, B);
        B = mul(B, B);
        p >>= 1;
    }
    return A;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s >> n;
    m = s.size();
    n += m;
    s = " " + s;

    dp[1][m][0] = 1;
    for (int l = m - 1; l >= 0; l--)
        for (int i = 1; i + l <= m; i++)
            for (int k = 0; k <= m / 2; k++)
            {
                int j = i + l;
                if (s[i] == s[j])
                    dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + dp[i][j][k]) % mod;
                else
                {
                    dp[i][j - 1][k] = (dp[i][j - 1][k] + dp[i][j][k]) % mod;
                    dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;
                }
            }
    int ans = 0;
    for (int i = m; i >= 0; i--)
        a[i] = t++;
    b[0] = a[0];
    c[0] = t++;
    for (int i = 1; i <= (m + 1) / 2; i++)
        b[i] = t++, c[i] = t++;

    mtx A(t, vector<int>(t, 0));
    for (int i = m; i >= 1; i--)
        A[a[i]][a[i - 1]] = 1, A[a[i]][a[i]] = 24;
    A[a[1]][c[0]] = 1;
    for (int i = 0; i <= (m + 1) / 2; i++)
        A[b[i]][b[i]] = 25,
        A[c[i]][c[i]] = 26;
    for (int i = 0; i < (m + 1) / 2; i++)
        A[b[i]][b[i + 1]] = 1, A[b[i]][c[i + 1]] = 1;
    A = fpow(A, n / 2);

    // Case 1: n is odd
    if (n % 2 == 1)
    {
        for (int k = 0; k <= m / 2; k++)
            for (int i = 1; i < m; i++)
            {
                int j = m - 2 * k;
                if (j >= 0)
                    ans = (ans + dp[i + 1][i][k] * A[a[j]][c[k]]) % mod;
            }
        ans = 26 * ans % mod;
        for (int k = 0; k <= m / 2; k++)
            for (int i = 1; i <= m; i++)
            {
                int j = m - 2 * k - 1;
                if (j >= 0)
                    ans = (ans + dp[i][i][k] * ((A[a[j]][c[k + 1]] * 26 + A[a[j]][b[k]]) % mod)) % mod;
            }
    }
    else
    {
        for (int k = 0; k <= m / 2; k++)
            for (int i = 1; i < m; i++)
            {
                int j = m - 2 * k;
                if (j >= 0)
                    ans = (ans + dp[i + 1][i][k] * A[a[j]][c[k]]) % mod;
            }
        for (int k = 0; k <= m / 2; k++)
            for (int i = 1; i <= m; i++)
            {
                int j = m - 2 * k - 1;
                if (j >= 0)
                    ans = (ans + dp[i][i][k] * A[a[j]][c[k + 1]]) % mod;
            }
    }
    cout << ans << '\n';
}