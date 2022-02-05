#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define ll long long
//#define int long long

const int mxans = 45, C = 500;

ll solve(int k, int m)
{
    bitset<200005> dp[C + 1] = {0};
    vector<int> v;
    for (int i = 0, j = 1; i <= k; i++, j = (j * 10) % k)
    {
        v.emplace_back(j);
        if (dp[1][j])
            break;
        dp[1][j] = 1;
        if (j == m)
            return 1;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 2; i < mxans; i++)
    {
        for (int j = 0; j < min((int)v.size(), C); j++)
            dp[i] |= (dp[i - 1] << v[j]);
        dp[i] |= (dp[i] >> k);
        if (dp[i][m])
            return i;
    }
    return mxans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, m;
        cin >> k >> m;
        cout << solve(k, m) << '\n';
    }
}