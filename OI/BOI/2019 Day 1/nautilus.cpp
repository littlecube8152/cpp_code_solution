#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

char c[505][505];
int R, C, M;
bitset<505> dp[505], init[505];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C >> M;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> c[i][j];
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (c[i][j] == '.')
                init[i][j] = dp[i][j] = 1;
    for (int k = 1; k <= M; k++)
    {
        char m;
        cin >> m;
        bitset<505> cur[505];
        if ((m == 'N' || m == '?'))
            for (int i = 1; i <= R; i++)
                cur[i] |= dp[i + 1];
        if ((m == 'S' || m == '?'))
            for (int i = 1; i <= R; i++)
                cur[i] |= dp[i - 1];
        if ((m == 'E' || m == '?'))
            for (int i = 1; i <= R; i++)
                cur[i] |= (dp[i] << 1);
        if ((m == 'W' || m == '?'))
            for (int i = 1; i <= R; i++)
                cur[i] |= (dp[i] >> 1);
        for (int i = 1; i <= R; i++)
            dp[i] = cur[i] & init[i];
    }
    int ans = 0;
    for (int i = 1; i <= R; i++)
        ans += dp[i].count();
    cout << ans << '\n';
}
