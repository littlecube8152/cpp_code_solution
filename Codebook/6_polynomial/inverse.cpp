#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define base ll
#define N 524288
const ll mod = 998244353, g = 3;
base omega[4 * N], omega_[4 * N];
int rev[4 * N];

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll inverse(ll a)
{
    return fpow(a, mod - 2);
}

void calcW(int n)
{
    ll r = fpow(g, (mod - 1) / n), invr = inverse(r);
    omega[0] = omega_[0] = 1;
    for (int i = 1; i < n; i++)
    {
        omega[i] = omega[i - 1] * r % mod;
        omega_[i] = omega_[i - 1] * invr % mod;
    }
}

void calcrev(int n)
{
    int k = __lg(n);
    for (int i = 0; i < n; i++)
        rev[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
                rev[i] ^= 1 << (k - j - 1);
}

vector<base> NTT(vector<base> poly, bool inv)
{
    base *w = (inv ? omega_ : omega);
    int n = poly.size();
    for (int i = 0; i < n; i++)
        if (rev[i] > i)
            swap(poly[i], poly[rev[i]]);

    for (int len = 1; len < n; len <<= 1)
    {
        int arg = n / len / 2;
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                base odd = w[j * arg] * poly[i + j + len] % mod;
                poly[i + j + len] = (poly[i + j] - odd + mod) % mod;
                poly[i + j] = (poly[i + j] + odd) % mod;
            }
    }
    if (inv)
        for (auto &a : poly)
            a = a * inverse(n) % mod;
    return poly;
}

vector<base> mul(vector<base> f, vector<base> g)
{
    int sz = 1 << (__lg(f.size() + g.size() - 1) + 1);
    f.resize(sz), g.resize(sz);
    calcrev(sz);
    calcW(sz);
    f = NTT(f, 0), g = NTT(g, 0);
    for (int i = 0; i < sz; i++)
        f[i] = f[i] * g[i] % mod;
    return NTT(f, 1);
}

vector<base> inv(vector<base> A)
{
    if (A.size() == 1)
        return vector<base>{inverse(A[0])};
    int sz = A.size();

    // B(x) = A(x)A(-x)
    // B is an even function (B(x) = B(-x)), so its odd terms are zero
    // T(x^2) = B(x);
    // A^-1(x) = A(-x)/A(x)A(-x) = A(-x)/B(x)

    vector<base> negA = A;
    for (int i = 0; i < sz; i++)
        if (i & 1)
            negA[i] = mod - negA[i];

    vector<base> B = mul(A, negA), T((sz + 1) / 2), invB(sz), invA;
    for (int i = 0; i < sz; i++)
        T[i / 2] += B[i];
    T = inv(T);
    for (int i = 0; i < (sz + 1) / 2; i++)
        invB[i * 2] = T[i];
    invA = mul(negA, invB);
    invA.resize(sz);
    return invA;
}

signed main()
{
    int n;
    cin >> n;
    vector<base> A(n), B;
    for (base &i : A)
        cin >> i;
    B = inv(A);
    for (int i = 0; i < n; i++)
        cout << B[i] << " \n"[i == n - 1];
}