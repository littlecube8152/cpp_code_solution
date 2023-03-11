#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, A[1048576], f[1048576][22], g[1048576][22], done[1048576];

char c[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int P = (N == 1 ? 0 : __lg(N - 1) + 1);

    for (int i = 0; i < (1 << P); i++)
    {
        for (int j = 1; j <= P; j++)
        {
            if (i & (1 << (j - 1)))
                f[i][j] = (f[i][j - 1] + f[i ^ (1 << (j - 1))][j - 1] + g[i ^ (1 << (j - 1))][P]) % (1 << 30);
            else
                f[i][j] = f[i][j - 1];
        }
        g[i][0] ^= (f[i][P] + A[i]) % (1 << 30);

        for (int j = 1; j <= P; j++)
        {
            if (i & (1 << (j - 1)))
                g[i][j] = g[i][j - 1] ^ g[i ^ (1 << (j - 1))][j - 1];
            else
                g[i][j] = g[i][j - 1];
        }
    }
    cout << (f[N - 1][P] + A[N - 1]) % (1 << 30) << '\n';
}