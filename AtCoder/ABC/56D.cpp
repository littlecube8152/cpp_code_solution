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

ll N, K, a[5005];
short fdp[5005][5005], bdp[5005][5005], ans;

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    fdp[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
        {
            if (j + a[i] <= K)
                fdp[i][j + a[i]] |= fdp[i - 1][j];
            fdp[i][j] |= fdp[i - 1][j];
        }
    bdp[N + 1][0] = 1;
    for (int i = N; i >= 1; i--)
        for (int j = 0; j <= K; j++)
        {
            if (j + a[i] <= K)
                bdp[i][j + a[i]] |= bdp[i + 1][j];
            bdp[i][j] |= bdp[i + 1][j];
        }
    ans = N;
    for (int i = 1; i <= N; i++)
        if (a[i] <= K)
        {
            for (int j = 1; j <= K; j++)
                bdp[i + 1][j] += bdp[i + 1][j - 1];

            bool has = 0;
            for (int j = 0; j < K; j++)
            {
                // 0 -> [K - a[i], K - 1]
                // 1 -> [K - a[i] - 1, K - 2]
                if (fdp[i - 1][j] && bdp[i + 1][K - 1 - j] - (j >= K - a[i] ? 0 : bdp[i + 1][K - a[i] - j - 1]) > 0)
                    has = 1;
            }
            ans -= has;
        }
        else
            ans--;
    cout << ans << '\n';
}
