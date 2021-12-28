#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll G, N, M, dp[110], caldp[110];

vector<pair<int, vector<int>>> v;

signed main()
{
    cin >> G >> N >> M;
    dp[0] = 1, dp[1] = 1, caldp[0] = 1, caldp[1] = 1;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        int size;
        cin >> v[i].F >> size;
        v[i].S.resize(size);
        for (int &j : v[i].S)
            cin >> j;
    }
    for (int i = 2; i < G; i++)
        dp[i] = 1e18;
    for (int i = 0; i < N * 10; i++)
    {
        for (auto j : v)
        {
            bool cal = true;
            for (auto k : j.S)
                cal &= caldp[k];
            if (cal)
            {
                __int128 res = 0;
                caldp[j.F] = 1;
                for (auto k : j.S)
                {
                    res += (__int128)dp[k];
                    if (res > 1e16)
                        break;
                }
                if (res < 1e16)
                    dp[j.F] = min(dp[j.F], (ll)res);
            }
        }
    }
    for (int i = 2; i < G; i++)
    {
        cout << "NO " << dp[i] << '\n';
        assert(dp[i] < 10000000000000000LL);
    }
}
