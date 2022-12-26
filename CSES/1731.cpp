/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

const ll base = 29, hmod = 1234567891, mod = 1000000007;

ll n, k, dp[5005];
string s, t[100005];
vector<ll> h[5005];

signed main()
{
    fast;
    cin >> s;
    n = s.size();
    s = '$' + s;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> t[i];
        if (t[i].size() <= n)
        {
            ll cur = 0;
            for (auto c : t[i])
                cur = (cur * base + c - 'a') % hmod;
            h[t[i].size()].emplace_back(cur);
        }
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        ll cur = 0;
        for (int j = 1; j <= n - i; j++)
        {
            cur = (cur * base + s[i + j] - 'a') % hmod;
            for(int k : h[j])
                if(k == cur)
                    dp[i + j] = (dp[i + j] + dp[i]) % mod;
        }
    }
    cout << dp[n] << '\n';
}
