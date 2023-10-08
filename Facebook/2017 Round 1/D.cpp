/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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
//using namespace __gnu_pbds;

#define LOCAL

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

int T;

const ll mod = 1e9 + 7;

ll fastpow(ll b, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return ans;
}

ll _fac[4000] = {1};

ll inv(ll b)
{
    return fastpow(b, mod - 2);
}

ll fac(ll k)
{
    assert(k >= 0);
    return _fac[k];
}

ll C(ll n, int k)
{
    ll ans = inv(fac(k));
    for (ll i = k, j = n; i >= 1; i--, j--)
        ans = ans * j % mod;
    return ans;
}

ll H(ll n, ll k)
{
    if (k < 0)
        return 0;
    return C(n - 1 + k, n - 1);
}

signed main()
{
    //ifstream cin("beach_umbrellas_input.txt");
    //ofstream cout("beach_umbrellas_output.txt");
    //fast;
    cin >> T;
    for (int i = 1; i < 4000; i++)
        _fac[i] = _fac[i - 1] * i % mod;
    for (int t = 1; t <= T; t++)
    {
        //std::cout << t << '\n';
        ll N, M, R[2005], tot, ans = 0;
        ll preans[4005], calc[4005] = {};
        cin >> N >> M;
        tot = M - 1;
        if (N == 1)
            ans = M;
        for (int i = 1; i <= N; i++)
        {
            cin >> R[i];
            tot -= 2 * R[i];
        }
        for (int i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++)
            {
                if (!calc[R[i] + R[j]])
                {
                    preans[R[i] + R[j]] = (2LL * H(N + 1, tot + R[i] + R[j]) % mod) * fac(N - 2) % mod;
                    calc[R[i] + R[j]] = 1;
                }
                ans = (ans + preans[R[i] + R[j]]) % mod;
            }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
