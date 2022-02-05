//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, c, u[2005], v[2005], w[1005], dp[1005][1005], res;
set<pii> st;
bool vis[1005][1005];

signed main()
{
    ifstream cin;
    cin.open("time.in");
    ofstream cout;
    cout.open("time.out");

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        st.insert(make_pair(x, y));
    }
    vis[0][1] = 1;
    for (ll i = 1; i <= 1000; i++)
    {
        for (auto j : st)
            if (vis[i - 1][j.F])
                if (dp[i - 1][j.F] >= 0)
                    dp[i][j.S] = max(dp[i][j.S], dp[i - 1][j.F] + w[j.S]), vis[i][j.S] = 1;

        res = max(res, dp[i][1] - i * i * c);
    }
    cout << res << '\n';
    assert(res >= 0);
}