
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, R, C, c1, c2;
char c;

constexpr int P = 1e9 + 7;

#ifdef EVAL
#include "arithmetics.h"
#else
int Add(int a, int b)
{
    int ret = a % P;
    ret = (ret < 0 ? P + ret : ret) + (b % P);
    return (ret >= 0 ? ret % P : ret + P);
}
int Sub(int a, int b)
{
    int ret = a % P;
    ret = (ret < 0 ? P + ret : ret) - (b % P);
    return (ret >= 0 ? ret % P : ret + P);
}
int Mul(int a, int b)
{
    int ret = (1ll * (a % P) * (b % P)) % P;
    return (ret < 0 ? P + ret : ret);
}
int modpow(int base, int exp, int modulus = P)
{
    base %= modulus;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (1ll * result * base) % modulus;
        base = (1ll * base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int modinv(int a, int modulus = P)
{
    return modpow(a, modulus - 2);
}
int Div(int a, int b)
{
    int ret = b % P;
    ret = (1ll * (a % P) * modinv(ret < 0 ? P + ret : ret)) % P;
    return (ret < 0 ? P + ret : ret);
}
#endif

#define matrix vector<vector<int>>

matrix mul(matrix m1, matrix m2, int size)
{
    matrix m(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
        for (int k = 0; k < size; k++)
            for (int j = 0; j < size; j++)
                m[i][j] = Add(m[i][j], Mul(m1[i][k], m2[k][j]));
    return m;
}

matrix fastpow(matrix base, ll p, int size)
{
    matrix a(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        a[i][i] = 1;
    while (p > 0)
    {
        if (p & 1)
            a = mul(a, base, size);
        p >>= 1;
        base = mul(base, base, size);
    }
    return a;
}

signed main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C >> N;
    matrix m(C, vector<int>(C, 0)), res;
    for (int i = 0; i < C; i++)
        for (int j = 0; j < C; j++)
            if (abs(i - j) <= 1)
                m[i][j] = 1;
    res = m;
    for (int i = 1; i <= N; i++)
    {
        res = mul(res, m, C);
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                cout << res[i][j] << " \n"[j == C - 1];
        cout << '\n';
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> c >> c1 >> c2;
        if (c == 'K')
            cout << R - 1 << " " << res[c1 - 1][c2 - 1] << '\n';
        else
            return 0;
    }
}