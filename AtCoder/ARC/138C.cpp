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

ll N, l, r, a[200005], b[200005], o[200005], p[400005], k = 0, ans = 0;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        b[i] = i;
    }
    sort(b + 1, b + 1 + N, [&](int i, int j)
         { return a[i] < a[j]; });
    for (int i = 1; i <= N; i++)
        o[b[i]] = i;
    for (int i = 1; i <= N; i++)
        if (o[i] <= N / 2)
            p[i] = p[i + N] = 1;
        else
        {
            p[i] = p[i + N] = -1;
            ans += a[i];
        }
    for (int i = 1; i <= 2 * N; i++)
        p[i] += p[i - 1];
    deque<pii> dq;
    for (int i = 2 * N - 1; i >= 1; i--)
    {
        while (!dq.empty() && dq.back().S > i + N - 1)
            dq.pop_back();
        while (!dq.empty() && p[i] < dq.front().F)
            dq.pop_front();
        dq.push_front(pii{p[i], i});
        if (i <= N && dq.back().F - p[i - 1] >= 0)
            k = i;
    }
    cout << k - 1 << " " << ans << '\n';
}
