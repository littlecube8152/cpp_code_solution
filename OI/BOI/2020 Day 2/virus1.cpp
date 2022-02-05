#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll G, N, M, dp[110];

vector<pair<int, vector<int>>> v;

signed main()
{
    cin >> G >> N >> M;
    dp[0] = 1, dp[1] = 1;
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
        dp[i] = 1e16;
    for (int i = 0; i < N; i++)
    {
        for (auto j : v)
        {
            bool cal = true;
            int res = 0;
            for(int k : j.S)
                res += dp[k];
            dp[j.F] = min(dp[j.F], res);
        }
    }
    for (int i = 2; i < G; i++)
        cout << "NO " << dp[i] << '\n';
}
