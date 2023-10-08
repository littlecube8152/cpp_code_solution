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

struct line
{
    ll a, b;
    ll value(ll x)
    {
        return a * x + b;
    }
};

ll n, k, dp[500005], a[500005], f[500005], s[500005];
deque<line> dq;

ll point(line l1, line l2)
{
    return (l2.b - l1.b - 1LL) / (l1.a - l2.a) + 1LL;
}

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        s[i] = s[i + 1] + a[i];
    for (int i = n - 1; i >= 0; i--)
        f[i] = f[i + 1] + s[i + 1];

    dp[0] = f[1];
    dq.push_front(line{0, 0});
    for (ll i = 1; i <= n; i++)
    {
        while (i - dq.front().a / 2 > k)
            dq.pop_front();
        while (dq.size() >= 2 && point(dq.front(), dq[1]) - 1 < i)
            dq.pop_front();
        dp[i] = dq.front().value(i) + f[i] - i * i;
        line l = line{2 * i, dp[i] - f[i + 1] - i * i};
        while (dq.size() >= 2 && point(dq.back(), l) - min(point(dq[dq.size() - 2], dq.back()) - 1, dq[dq.size() - 2].a / 2 + k) <= 1)
            dq.pop_back();
        dq.push_back(l);
    }
    //for (int i = 0; i <= n; i++)
    //    cout << dp[i] << " \n"[i == n];
    cout << dp[n] << '\n';
}
