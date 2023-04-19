#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
const int kL = 20;
const int kN = 1 << kL;

ll k, N, A[1 << 20], B[1 << 20], C[1 << 20], X[20];

const int T[3][2][2] =
    {
        {{1, 1},
         {0, 1}}, // AND
        {{1, 0},
         {1, 1}}, // OR
        {{1, -1},
         {1, 1}}, // XOR
};

const int invT[3][2][2] =
    {
        {{1, -1},
         {0, 1}}, // AND
        {{1, 0},
         {-1, 1}}, // OR
        {{499122177, 499122177},
         {-499122177, 499122177}}, // XOR
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> k;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int p = 0; p < k; p++)
        cin >> X[p];
    for (int p = 0; p < k; p++)
    {
        int len = 1 << p;
        for (int i = 0; i < N; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                int t = X[p] % 3;

                tie(A[i + j], A[i + j + len]) =
                    make_pair((T[t][0][0] * A[i + j] + T[t][0][1] * A[i + j + len] + mod * mod) % mod,
                              (T[t][1][0] * A[i + j] + T[t][1][1] * A[i + j + len] + mod * mod) % mod);
            }
    }

    for (int p = 0; p < k; p++)
    {
        int len = 1 << p;
        for (int i = 0; i < N; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                int t = X[p] % 3;

                tie(B[i + j], B[i + j + len]) =
                    make_pair((T[t][0][0] * B[i + j] + T[t][0][1] * B[i + j + len] + mod * mod) % mod,
                              (T[t][1][0] * B[i + j] + T[t][1][1] * B[i + j + len] + mod * mod) % mod);
            }
    }

    for (int i = 0; i < N; i++)
        C[i] = A[i] * B[i] % mod;

    for (int p = 0; p < k; p++)
    {
        int len = 1 << p;
        for (int i = 0; i < N; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                int t = X[p] % 3;

                tie(C[i + j], C[i + j + len]) =
                    make_pair((invT[t][0][0] * C[i + j] + invT[t][0][1] * C[i + j + len] + mod * mod) % mod,
                              (invT[t][1][0] * C[i + j] + invT[t][1][1] * C[i + j + len] + mod * mod) % mod);
                if (X[p] >= 3)
                    swap(C[i + j], C[i + j + len]);
            }
    }

    for (int i = 0; i < N; i++)
        cout << C[i] << " \n"[i == N - 1];
}