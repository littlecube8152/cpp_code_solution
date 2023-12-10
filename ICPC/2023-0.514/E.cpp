/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
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

int n, dp[2005][2005], S[2005][26], T[2005][26];

void solve()
{

    string s, t;
    cin >> n >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    s = '#' + s;
    t = '$' + t;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = n + 1;
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            S[i][j] = S[i - 1][j] + (s[i] - 'a' == j);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            T[i][j] = T[i - 1][j] + (t[i] - 'a' == j);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            // cerr << dp[i][j] << " \n"[j == n];
            // what can we do?
            // 1. operate on s[i]
            // 2. match s[i], t[i]
            // 3. match operated, t[i]

            if (i < n)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

            if (i < n && j < n)
                if (s[i + 1] == t[j + 1])
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);

            if (j < n)
                if (S[i][t[j + 1] - 'a'] - T[j][t[j + 1] - 'a'] > 0)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    if(dp[n][n] == n + 1)
        dp[n][n] = -1;
    cout << dp[n][n] << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
