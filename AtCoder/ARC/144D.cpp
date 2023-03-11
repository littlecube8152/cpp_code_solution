/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
// #include <bits/extc++.h>
#include <bits/stdc++.h>
// #pragma pack(0)
// #define int long long
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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll mod = 998244353;
ll N, K, fac[300005], ifac[300005], p2[300005], Kfac = 1, ans;

signed main()
{
    fast;
    cin >> N >> K;
    fac[0] = ifac[0] = ifac[1] = p2[0] = 1;
    for (int i = 2; i <= N + 1; i++)
        ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
    for (int i = 1; i <= N + 1; i++)
        fac[i] = fac[i - 1] * i % mod,
        ifac[i] = ifac[i - 1] * ifac[i] % mod,
        p2[i] = p2[i - 1] * 2 % mod;
    for (int i = 0; i <= N; i++)
    {
        Kfac = Kfac * ((K + 1 - i) % mod) % mod;
        ans = ans + fac[N] * ifac[i] % mod * ifac[N - i] % mod * Kfac % mod * ifac[i + 1] % mod * p2[i] % mod;
    }
    cout << ans % mod << '\n';
}
