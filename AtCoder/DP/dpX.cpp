/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll N, M, dp[20005];
vector<pair<pll, ll>> vec;
signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        ll w, s, v;
        cin >> w >> s >> v;
        vec.pb(make_pair(make_pair(s, w), v));
    }
    sort(vec.begin(), vec.end(), [](pair<pll, ll> p1, pair<pll, ll> p2) { return p1.F.F - p2.F.S < p2.F.F - p1.F.S; });
    for(auto i : vec)
        for (int j = i.F.F; j >= 0; j--)
            dp[j + i.F.S] = max(dp[j + i.F.S], dp[j] + i.S);

    ll ans = 0;
    for (int i = 0; i <= 20000; i++)
        ans = max(ans, dp[i]);

    cout << ans << '\n';
}
