/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll k;
signed main()
{
    fast;
    cin >> k;
    const int mxans = 45, C = 500;

    bitset<200005> dp[45] = {0};
    vector<int> v;
    for (int i = 0, j = 1; i <= k; i++, j = (j * 10) % k)
    {
        v.emplace_back(j);
        if (dp[1][j])
            break;
        dp[1][j] = 1;
        if (j == 0)
        {
            cout << 1 << '\n';
            return 0;
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 2; i < mxans; i++)
    {
        for (int j = 0; j < min((int)v.size(), C); j++)
            dp[i] |= (dp[i - 1] << v[j]);
        dp[i] |= (dp[i] >> k);
        if (dp[i][0])
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 45 << '\n';
}
