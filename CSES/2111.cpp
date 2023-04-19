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
const double PI = 2.0 * acosl(0);
vector<base> FFT(vector<base> &poly, bool inv)
{
    int n = poly.size();
    if (n == 1)
        return poly;
    double arg = 2.0 * PI / n;
    if (inv)
        arg = -arg;
    vector<base> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = poly[i * 2];
        odd[i] = poly[i * 2 + 1];
    }
    even = FFT(even, inv);
    odd = FFT(odd, inv);
    base x = 1, w = base(cos(arg), sin(arg));
    for (int i = 0; i < n / 2; i++)
    {
        poly[i] = even[i] + odd[i] * x;
        poly[i + n / 2] = even[i] - odd[i] * x;
        x *= w;
    }
    if (inv)
        for (int i = 0; i < n; i++)
            poly[i] *= 0.5;
    return poly;
}

signed main()
{
    fast;
    int n, m, k, sz;
    cin >> k >> n >> m;
    sz = 1 << (__lg(2 * k) + 1);
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