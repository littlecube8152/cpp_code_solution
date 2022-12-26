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
// using namespace __gnu_pbds;

map<int, int> mp;

int solve(ll A)
{
    if (A == 0)
        return 0;
    else if (A < 0)
        return 100;
    if (A > 0 && mp[A])
        return mp[A];

    int ans = 100;
    for (int i = 0; i <= 20; i++)
    {
        int q = solve(A / 10 - i), r = 10 * i + A % 10;
        if (q <= r)
            ans = min(ans, max(q, (r + 2) / 3));
    }
    // cout << "solve " << A << " = " << ans << '\n';
    mp[A] = ans;
    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        ll A;
        cin >> A;
        cout << solve(A) << '\n';
    }
}
