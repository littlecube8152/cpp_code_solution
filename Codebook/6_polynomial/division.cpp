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
    int osz = f.size() + g.size() - 1;
    int sz = 1 << (__lg(f.size() + g.size() - 1) + 1);
    f.resize(sz), g.resize(sz);
    calcrev(sz);
    calcW(sz);
    f = NTT(f, 0), g = NTT(g, 0);
    for (int i = 0; i < sz; i++)
        f[i] = f[i] * g[i] % mod;
    f = NTT(f, 1);
    f.resize(osz);
    return f;
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

    return invA;
}

pair<vector<base>, vector<base>> div(vector<base> A, vector<base> B)
{
    if (A.size() < B.size())
        return make_pair(vector<base>(), A);
    // A = QB + R
    // A_i = sum{j+k=i} Q_j B_k + R_i
    // discard i if i < deg B = m
    // it is sufficient to compute Q since Q is uniquely determined regardless of A_i (i < m)
    int n = A.size(), m = B.size();
    vector<base> revA = A, invrevB = B;
    reverse(revA.begin(), revA.end());
    reverse(invrevB.begin(), invrevB.end());
    revA.resize(n - m + 1);
    invrevB.resize(n - m + 1);
    invrevB = inv(invrevB);

    vector<base> Q = mul(revA, invrevB);
    Q.resize(n - m + 1);
    reverse(Q.begin(), Q.end());
    vector<base> R = mul(Q, B);
    R.resize(m - 1);
    for (int i = 0; i < m - 1; i++)
        R[i] = (A[i] - R[i] + mod) % mod;
    return make_pair(Q, R);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<base> A(n), B(m), Q, R;
    for (base &i : A)
        cin >> i;
    for (base &i : B)
        cin >> i;
    tie(Q, R) = div(A, B);
    while(!R.empty() && R.back() == 0)
        R.pop_back();
    cout << Q.size() << ' ' << R.size() << '\n';
    for (int i = 0; i < Q.size(); i++)
        cout << Q[i] << " \n"[i + 1 == Q.size()];
    if (Q.empty())
        cout << '\n';
    for (int i = 0; i < R.size(); i++)
        cout << R[i] << " \n"[i + 1 == R.size()];
    if (R.empty())
        cout << '\n';
}