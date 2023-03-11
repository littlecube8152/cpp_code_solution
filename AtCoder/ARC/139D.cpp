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

const ll mod = 998244353;
int N, M, K, X, pre[4005];
ll way[2005][2005], C[4005][4005], ans;

ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while(p)
    {
        if(p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

signed main()
{
    fast;
    cin >> N >> M >> K >> X;
    for (int i = 1; i <= N; i++)
    {
        int A;
        cin >> A;
        pre[A]++;
    }
    for (int i = 1; i <= M; i++)
        pre[i] += pre[i - 1];
    for (int i = 0; i <= N + K; i++)
        for (int j = 0; j <= i; j++)
            C[i][j] = ((j == 0 || j == i) ? 1 : C[i - 1][j - 1] + C[i - 1][j]) % mod;

    for (int j = 1; j <= M; j++)
    {
        int r = 0;
        ll p = 1;
        for (int k = 1; k <= K; k++)
            p = p * (M - j + 1) % mod;
        for (int i = 1; i <= N; i++)
        {
            int nr = (i < X ? i - 1 - pre[j - 1] : i + K - 1 - pre[j - 1]);
            way[i][j] = way[i - 1][j];
            while (r <= nr)
            {
                way[i][j] = (way[i][j] + C[K][r] * p) % mod;
                p = p * (j - 1) % mod * inv(M - j + 1) % mod;
                r++;
            }
            }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            way[i][j] = (way[i][j] - way[i][j + 1] + mod) % mod;
            // cerr << i << ' ' << j << ' ' << way[i][j] << '\n';
            ans = (ans + j * way[i][j]) % mod;
        }

    cout << ans << '\n';
}
