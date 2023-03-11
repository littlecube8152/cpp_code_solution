#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

constexpr const ll mod = 1'000'000'007;
constexpr int sz = 200000;

constexpr std::array<ll, sz> get_fac()
{
    std::array<ll, sz> fac{};
    fac[0] = 1;
    for (int i = 1; i < sz; i++)
        fac[i] = fac[i - 1] * i % mod;
    return fac;
}

std::array<ll, sz> get_ifac()
{
    std::array<ll, sz> ifac{};
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i < sz; ++i)
        ifac[i] = (-mod / i) * ifac[mod % i] % mod;
    for (int i = 1; i < sz; ++i)
        ifac[i] = ifac[i] * ifac[i - 1] % mod;
    return ifac;
}

constexpr std::array<ll, sz> fac = get_fac();
std::array<ll, sz> ifac = get_ifac();

ll N, H, W, dp[3005];
pii p[3005];

ll ways(int x, int y)
{
    return fac[x + y] * ifac[x] % mod * ifac[y] % mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> H >> W >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;

    N++;
    p[N] = pii(H, W);
    sort(p + 1, p + 1 + N);

    for (int i = 1; i <= N; i++)
    {
        dp[i] = ways(p[i].F - 1, p[i].S - 1);
        for (int j = 1; j < i; j++)
            if (p[j].S <= p[i].S)
                dp[i] = (dp[i] - dp[j] * ways(p[i].F - p[j].F, p[i].S - p[j].S)) % mod;
    }

    cout << (dp[N] + mod) % mod << '\n';
}