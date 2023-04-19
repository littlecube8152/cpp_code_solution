/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll N, A[200005], K, j[200005][45], w[200005][45], cur = 0, ans;

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> w[i][0];
    for (int i = 0; i < N; i++)
        j[i][0] = (i + w[i][0]) % N;
    for (int p = 1; p <= 40; p++)
        for (int i = 0; i < N; i++)
            w[i][p] = w[i][p - 1] + w[j[i][p - 1]][p - 1], j[i][p] = j[j[i][p - 1]][p - 1];
    for (ll p = 40; p >= 0; p--)
        if (K & (1LL << p))
        {
            ans += w[cur][p];
            cur = j[cur][p];
        }
    cout << ans << '\n';
}
