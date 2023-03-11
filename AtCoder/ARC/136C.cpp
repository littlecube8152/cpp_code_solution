/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #pragma pack(0)
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

ll N, A[200005], s[200005], f[200005], ans;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        ans += A[i];
    }
    for (int i = 2; i <= N; i++)
        ans -= min(A[i - 1], A[i]);

    int l = 0, r = A[1], h = A[1];
    for (int i = 2; i <= N + 1; i++)
    {
        if (A[i] >= h - l)
            h = l + A[i];
        else
        {
            int nl = min(r, h - A[i]);
            s[i - 1] = nl - l;
            l = nl;
            if (l == r)
                break;
        }
    }

    l = 0, r = A[N], h = A[N];
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] >= h - l)
            h = l + A[i];
        else
        {
            int nl = min(r, h - A[i]);
            f[i + 1] = nl - l;
            l = nl;
            if (l == r)
                break;
        }
    }

    for (int i = N; i >= 1; i--)
    {
        ans -= min(s[i], f[i + 1]);
        f[i + 1] -= min(s[i], f[i + 1]);
        f[i] += f[i + 1];
    }

    cout << ans << '\n';
}
