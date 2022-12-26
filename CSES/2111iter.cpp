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

#define base complex<double>
const double PI = acosl(-1);

base omega[600005], omega_[600005];
int rev[6000005];

void calcW(int n)
{
    double arg = 2.0 * PI / n;
    for (int i = 0; i < n; i++)
    {
        omega[i] = base(cos(i * arg), sin(i * arg));
        omega_[i] = base(cos(-i * arg), sin(-i * arg));
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

vector<base> FFT(vector<base> &poly, bool inv)
{
    base *w = (inv ? omega_ : omega);
    int n = poly.size(), k = __lg(n);
    for (int i = 0; i < n; i++)
        if (rev[i] > i)
            swap(poly[i], poly[rev[i]]);
        
    for (int len = 1; len < n; len <<= 1)
    {
        int arg = n / len / 2;
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                base odd = w[j * arg] * poly[i + j + len];
                poly[i + j + len] = poly[i + j] - odd;
                poly[i + j] += odd;
            }
    }
    if (inv)
        for (auto &a : poly)
            a /= n;
    return poly;
}

signed main()
{
    fast;
    int n, m, k, sz;
    cin >> k >> n >> m;
    sz = 1 << (__lg(2 * k) + 1);
    calcW(sz);
    calcrev(sz);
    vector<base> A(sz), B(sz);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        A[a] += 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int b;
        cin >> b;
        B[b] += 1;
    }
    A = FFT(A, 0), B = FFT(B, 0);
    for (int i = 0; i < sz; i++)
        A[i] *= B[i];
    A = FFT(A, 1);
    for (int i = 2; i <= 2 * k; i++)
        cout << (ll)round(real(A[i])) << " \n"[i == 2 * k];
}