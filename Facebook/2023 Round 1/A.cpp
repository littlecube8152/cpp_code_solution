/*
    Remember to turn off all debug flags!
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

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

int T, N;
double X[1000005];

signed main()
{
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> X[i];
        sort(X + 1, X + 1 + N);
        double ans;
        if (N == 5)
            ans = max((X[N] + X[N - 1]) / 2 - (X[3] + X[1]) / 2,
                      (X[N] + X[N - 2]) / 2 - (X[2] + X[1]) / 2);
        else
            ans = (X[N] + X[N - 1]) / 2 - (X[2] + X[1]) / 2;
        cout << "Case #" << t << ": " << fixed << setprecision(1) << ans << '\n';
    }
}
