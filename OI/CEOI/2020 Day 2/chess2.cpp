//#include "arithmetics.h"
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

#ifndef EVAL
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

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> c >> c1 >> c2;
        if (c == 'P')
        {
            if (c1 == c2)
                cout << R - 1 << " " << 1 << '\n';
            else
                cout << "0 0\n";
        }
        else if (c == 'R')
            cout << (c1 == c2 ? "1 1\n" : "2 2\n");
        else if (c == 'Q')
        {
            if (c1 == c2 || abs(c2 - c1) + 1 == R)
            {
                cout << "1 1\n";
                continue;
            }
            int ans = 4;
            if ((c1 == 1 || c1 == R) && R == C)
                ans++;
            if ((c2 == 1 || c2 == R) && R == C)
                ans++;
            if ((c1 + c2 + R - 1) % 2 == 0 && (c1 + c2 + R - 1) <= 2 * C)
                ans++;
            if ((c1 + c2 - R + 1) % 2 == 0 && (c1 + c2 - R + 1) >= 2)
                ans++;
            cout << 2 << " " << ans << '\n';
        }
    }
}