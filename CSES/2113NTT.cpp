/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const ll mod = 998244353, g = 3;

ll omega[1200005], omega_[1200005];
ll rev[1200005];

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

ll inverse(ll b)
{
    return fpow(b, mod - 2);
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
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
                rev[i] ^= 1 << (k - j - 1);
}

vector<ll> NTT(vector<ll> &poly, bool inv)
{
    ll *w = (inv ? omega_ : omega);
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
                ll odd = w[j * arg] * poly[i + j + len] % mod;
                poly[i + j + len] = (poly[i + j] - odd + mod) % mod;
                poly[i + j] = (poly[i + j] + odd) % mod;
            }
    }
    if (inv)
        for (auto &a : poly)
            a = a * inverse(n) % mod;
    return poly;
}

signed main()
{
    fast;
    int n, m, sz;
    cin >> n >> m;
    sz = 1 << (__lg(n + m - 1) + 1);
    calcrev(sz);
    calcW(sz);
    vector<ll> A(sz), B(sz);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = m - 1; i >= 0; i--)
        cin >> B[i];
    A = NTT(A, 0), B = NTT(B, 0);
    for (int i = 0; i < sz; i++)
        A[i] *= B[i];
    A = NTT(A, 1);
    for (int i = 0; i < n + m - 1; i++)
        cout << (ll)round(real(A[i])) << " \n"[i == n + m - 2];
}