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
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int N, K, a[400005], pos[400005], ans = 1e7, idx;
map<int, int> mp;

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    for (auto &[_, i] : mp)
        i = ++idx;
    for (int i = 1; i <= N; i++)
        a[i] = mp[a[i]];
    for (int i = 1; i <= K; i++)
        pos[a[i]] = i;
    for (int i = 1; i <= N; i++)
        pos[i] = max(pos[i], pos[i - 1]);
    for (int i = K + 1; i <= N; i++)
        if (pos[a[i] - 1])
            ans = min(i - pos[a[i] - 1], ans);
    cout << (ans >= 1e7 ? -1 : ans) << '\n';
}
