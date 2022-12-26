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
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
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

const ll mod = 1'000'000'007;

ll solve()
{
    ll N, Q, ans = 0, sumA = 0, sumAA = 0, sumB = 0, sumBB = 0;
    cin >> N;
    vector<ll> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
        sumAA = (sumAA + A[i] * A[i]) % mod;
        sumBB = (sumBB + B[i] * B[i]) % mod;
        sumA = (sumA + A[i]) % mod;
        sumB = (sumB + B[i]) % mod;
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        ll X, Y, res;
        cin >> X >> Y;
        res = ((N * ((X * X + Y * Y) % mod) + sumAA + sumBB - (2 * (sumA * X + sumB * Y) % mod)) % mod + mod) % mod;
        ans = (ans + res) % mod;
    }
    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        cout << "Case #" << t << ": " << solve() << '\n';
}
