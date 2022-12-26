#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#define ll long long
using namespace std;

const ll mod = 1000000007;
ll n, fac[1000006], invfac[1000006], onethreesix[1000006];

inline ll c(int n, int k)
{
    return (fac[n] * invfac[k] % mod) * invfac[n - k] % mod;
}

inline ll hulan(int i, int j)
{
    return (c(i + 1, i - j - 1) * fac[j] % mod) * onethreesix[j] % mod;
}

signed main()
{
    cin >> n;
    fac[0] = invfac[0] = invfac[1] = 1;
    for (int i = 1; i <= n + 1; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 2; i <= n + 1; i++)
        invfac[i] = mod - (invfac[mod % i] * (mod / i) % mod);
    for (int i = 2; i <= n + 1; i++)
        invfac[i] = invfac[i - 1] * invfac[i] % mod;
    for (int i = 1; i <= n + 1; i++)
        onethreesix[i] = (onethreesix[i - 1] + i) % mod;
        
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans = (ans + hulan(n, i)) % mod;
    cout << ans << '\n';
}