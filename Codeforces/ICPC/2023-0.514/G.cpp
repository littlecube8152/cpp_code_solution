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

const ll mod = 1234567891;
int n, q;
ll dp[10004], ans[10004];
vector<int> in[10004], out[10004];

ll safe(ll a)
{
    return (a >= mod ? a - mod : (a < 0 ? a + mod : a));
}

signed main()
{
    fast;
    cin >> n >> q;
    dp[0] = 1;
    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        in[l].emplace_back(x);
        out[r].emplace_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : in[i])
            for (int j = n; j >= x; j--)
                dp[j] = safe(dp[j] + dp[j - x]);
        for (int j = 1; j <= n; j++)
            ans[j] |= dp[j];
        for (auto x : out[i])
            for (int j = x; j <= n; j++)
                dp[j] = safe(dp[j] - dp[j - x]);
    }
    vector<int> sol;
    for (int j = 1; j <= n; j++)
        if(ans[j])
            sol.emplace_back(j);
    cout << sol.size() << '\n';
    for (auto j : sol)
        cout << j << ' ';
    cout << '\n';
}
