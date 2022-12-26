/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
// #define int long long
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
// using namespace __gnu_pbds;

ll H, W, N, ans[10];
map<pii, int> mp;

signed main()
{
    fast;
    cin >> H >> W >> N;
    for (int i = 1; i <= N; i++)
    {
        ll a, b;
        cin >> a >> b;
        for (int i = max(2LL, a - 1); i <= min(H - 1, a + 1); i++)
            for (int j = max(2LL, b - 1); j <= min(W - 1, b + 1); j++)
                mp[pii(i, j)]++;
    }
    for (auto [p, s] : mp)
        ans[s]++, ans[0]--;
    ans[0] += (H - 2) * (W - 2);
    for (int i = 0; i <= 9; i++)
        cout << ans[i] << '\n';
}
