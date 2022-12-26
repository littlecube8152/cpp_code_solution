/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

const ll mod = MOD;
ll fac[1000006];

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

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

ll C(int n, int m)
{
    if (m < 0 || m > n)
        return 0;
    return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

ll ans = 0;

signed main()
{
    fast;
    int N, K;
    cin >> N >> K;
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mod;
    if (K == 0)
        ans = fpow(3, N);
    else
        for (int i = 1; K + i <= N + 1 && i <= K; i++)
        {
            // 0111101110110111...
            if (K + i <= N)
                ans = (ans + C(K - 1, i - 1) * fpow(3, K - i) % mod * (C(N - K, i) * fpow(3, N - K - i) % mod)) % mod;
            if (K + i <= N + 1)
                ans = (ans + C(K - 1, i - 1) * fpow(3, K - i) % mod * (C(N - K, i - 1) * fpow(3, N - K - i + 1) % mod)) % mod;
        }
    cout << ans << '\n';
}
