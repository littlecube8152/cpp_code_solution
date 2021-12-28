/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

ll fpow(ll b, ll p)
{
    ll ans = 1, m = b;
    while (p)
    {
        if (p & 1)
            ans = ans * m % MOD;
        m = m * m % MOD;
        p >>= 1;
    }
    return ans;
}

int T;

signed main()
{
    ifstream cin("traffic_control_input.txt");
    ofstream cout("traffic_control_output.txt");
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        if (A < N + M - 1 || B < N + M - 1)
            cout << "Case #" << t << ": "
                 << "Impossible" << '\n';
        else
        {
            cout << "Case #" << t << ": "   
                 << "Possible" << '\n';
            cout << A - N - M + 2 << ' ';
            for (int i = 2; i < M; i++)
                cout << 1 << ' ';
            cout << B - N - M + 2 << '\n';
            for (int i = 2; i <= N; i++)
                for (int j = 1; j <= M; j++)
                    cout << 1 << " \n"[j == M];
        }
    }
}
