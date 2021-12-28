#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 2147483647 / 2
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
vector<vector<bool>> mp;
vector<int> meal[4], dp[2];
int n[4];
signed main()
{
    fast;
    cin >> n[0] >> n[1] >> n[2] >> n[3];

    for (int m = 1; m <= 4; m++)
    {
        meal[m - 1].resize(n[m - 1]);
        for (int i = 0; i < n[m - 1]; i++)
            cin >> meal[m - 1][i];
    }
    dp[0] = vector<int>(n[0]);
    for (int i = 0; i < n[0]; i++)
        dp[0][i] = meal[0][i];

    for (int m = 2; m <= 4; m++)
    {
        mp.clear();
        dp[(m - 1) % 2] = vector<int>(n[m - 1], _INFINITY);
        int i;
        cin >> i;
        while (i--)
        {
            int x, y;
            cin >> x >> y;
            mp[x - 1][y - 1] = 1;
        }
        for (int i = 0; i < n[m - 1]; i++)
            for (int j = 0; j < n[m - 2]; j++)
                if (!mp[i][j])
                    dp[(m - 1) % 2][i] = min(dp[(m - 1) % 2][i], dp[(m - 2) % 2][j] + meal[m - 1][i]);
    }

    int res = _INFINITY;
    for (int i = 0; i < n[3]; i++)
        res = min(res, dp[1][i]);
    if (res >= _INFINITY)
        cout << -1;
    else
        cout << res;
}