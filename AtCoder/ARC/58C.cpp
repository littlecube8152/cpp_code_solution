/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

ll n, x, y, z, dp[41][1 << 17], p[41], ans;
int uni, target;
const int mod = MOD;

signed main()
{
    cin >> n >> x >> y >> z;
    dp[0][0] = 1;
    uni = (1 << (x + y + z)) - 1;
    target = (1 << (x + y + z - 1)) ^ (1 << (y + z - 1)) ^ (1 << (z - 1));
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * 10 % mod;
    for (int i = 0; i <= n; i++)
        for (int mask = 0; mask <= uni; mask++)
        {
            if ((mask & target) == target)
                ans = (ans + dp[i][mask] * p[n - i]) % mod;
            else if (i < n)
            {
                int nxt = (mask << 1 | 1) & uni;
                for (int j = 0; j < 10; j++, nxt = ((nxt << 1) & uni))
                    dp[i + 1][nxt] = (dp[i + 1][nxt] + dp[i][mask]) % mod;
            }
        }
    cout << ans << '\n';
}
