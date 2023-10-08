#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace
{
#define base ll
#define P 18
#define N 1 << 18
    const ll mod = 998244353, g = 3;
    base omega[N], omega_[N];
    int rev[P + 1][N];

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

    void calcrev(int n, int *rev)
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
        int *r = rev[__lg(n)];
        for (int i = 0; i < n; i++)
            if (r[i] > i)
                swap(poly[i], poly[r[i]]);

        for (int len = 1; len < n; len <<= 1)
        {
            int arg = (N) / len / 2;
            for (int i = 0; i < n; i += 2 * len)
                for (int j = 0; j < len; j++)
                {
                    base odd = w[j * arg] * poly[i + j + len] % mod;
                    poly[i + j + len] = (poly[i + j] - odd + mod) % mod;
                    poly[i + j] = (poly[i + j] + odd) % mod;
                }
        }
        ll invn = inverse(n);
        if (inv)
            for (auto &a : poly)
                a = a * invn % mod;
        return poly;
    }

    vector<base> mul(vector<base> f, vector<base> g)
    {
        int osz = f.size() + g.size() - 1;
        int sz = 1 << (__lg(f.size() + g.size() - 1) + 1);
        f.resize(sz), g.resize(sz);
        f = NTT(f, 0), g = NTT(g, 0);
        for (int i = 0; i < sz; i++)
            f[i] = f[i] * g[i] % mod;
        f = NTT(f, 1);
        f.resize(osz);
        return f;
    }

    vector<base> inv(vector<base> A)
    {
        A.resize(1 << (__lg(A.size() - 1) + 1));
        vector<base> B = {inverse(A[0])};
        for (int n = 1; n < A.size(); n += n)
        {
            vector<base> pA(A.begin(), A.begin() + 2 * n);
            pA.resize(4 * n);
            B.resize(4 * n);
            pA = NTT(pA, 0);
            B = NTT(B, 0);
            for (int i = 0; i < 4 * n; i++)
                B[i] = ((B[i] * 2 - pA[i] * B[i] % mod * B[i]) % mod + mod) % mod;
            B = NTT(B, 1);
            B.resize(2 * n);
        }
        return B;
    }

    vector<base> div(vector<base> A, vector<base> B)
    {
        if (A.size() < B.size())
            return A;
        // A = QB + R
        // A_i = sum{j+k=i} Q_j B_k + R_i
        // discard i if i < deg B = m
        // it is sufficient to compute Q since Q is uniquely determined regardless of A_i (i < m)
        int n = A.size(), m = B.size();
        vector<base> Q = A, R = B;
        reverse(Q.begin(), Q.end());
        reverse(R.begin(), R.end());
        Q.resize(n - m + 1);
        R.resize(n - m + 1);
        R = inv(R);
        Q = mul(Q, R);
        Q.resize(n - m + 1);
        reverse(Q.begin(), Q.end());
        R = mul(Q, B);
        R.resize(m - 1);
        for (int i = 0; i < m - 1; i++)
            R[i] = (A[i] - R[i] + mod) % mod;
        return R;
    }

    ll fast_kitamasa(ll k, vector<base> A, vector<base> C)
    {
        int n = A.size();
        C.emplace_back(mod - 1);
        vector<base> Q, R = {0, 1}, F = {1};

        R = div(R, C);
        while (k)
        {
            if (k & 1)
                F = div(mul(F, R), C);
            R = div(mul(R, R), C);
            k >>= 1;
        }
        ll ans = 0;
        for (int i = 0; i < F.size(); i++)
            ans = (ans + A[i] * F[i]) % mod;
        return ans;
    }
}

signed main()
{
    calcW(N);
    for (int i = 0; i <= P; i++)
        calcrev(1 << i, rev[i]);
    ll n, k;
    cin >> n >> k;
    vector<base> A(n), C(n);
    for (base &i : A)
        cin >> i;
    for (base &i : C)
        cin >> i;
    cout << fast_kitamasa(k, A, C) << '\n';
}