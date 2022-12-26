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

ll p[2], t[2], h, s, dp[5005], tr[5005];

signed main()
{
    cin >> p[0] >> t[0] >> p[1] >> t[1] >> h >> s;
    for (int i = 0; i <= h; i++)
        dp[i] = tr[i] = 1e18;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= h; j++)
        {
            int dmg = min(i * p[0] + j * p[1] - (i + j - 1) * s, h);
            tr[dmg] = min(tr[dmg], max(i * t[0], j * t[1]));
        }
    for (int i = 1; i <= h; i++)
    {
        int dmg = min(i * (p[0] - s), h);
        tr[dmg] = min(tr[dmg], i * t[0]);
    }
    for (int i = 1; i <= h; i++)
    {
        int dmg = min(i * (p[1] - s), h);
        tr[dmg] = min(tr[dmg], i * t[1]);
    }

    dp[h] = 0;
    for (int i = h; i > 0; i--)
        for (int j = 1; j <= h; j++)
        {
            int k = max(0, i - j);
            dp[k] = min(dp[k], dp[i] + tr[j]);
        }

    cout << dp[0] << '\n';
}
