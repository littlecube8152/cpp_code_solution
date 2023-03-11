#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int mod = 998244353, off = 2501;
int N;
ll dp[5005][5005][2], ans;

int match(string &s, int i, string t)
{
    if ((s[i - 1] == t[0] || s[i - 1] == '?') && (s[i] == t[1] || s[i] == '?'))
        return 1;
    return 0;
}

void solve(string s)
{
    s.push_back(s[0]);

    for (int i = 0; i <= N; i++)
        for (int j = -N / 2; j <= N / 2; j++)
            dp[i][j + off][0] = dp[i][j + off][1] = 0;
    dp[0][off][s[0] == 'Y' ? 0 : 1] = 1;

    // PRY = YRP <=> PR = RP
    // consider PRP contributes both
    // therefore
    // B -> P      P -> R (+1)
    // B -> Y      P -> B
    // R -> Y      Y -> B
    // R -> P (-1) Y -> R
    // (x + 1) ^ N
    // [0B] -> [0Y, 0P] -> [0R, 0B, 1R] -> [-1P, 0Y, 0P, 1Y] -> [-1B, 0R, 0B, 1R, 1B]
    // [0R, 0B] -> [-1P, 0Y, 0P] -> [-1B, 0R, 0B, 1R]

    for (int i = 1; i <= N; i++)
        for (int j = -N / 2; j <= N / 2; j++)
        {
            // YBY, YRY
            dp[i][j + off][0] = (dp[i][j + off][0] + dp[i - 1][j + off][0] * (match(s, i * 2, "BY") + match(s, i * 2, "RY"))) % mod;
            // PBY
            dp[i][j + off][0] = (dp[i][j + off][0] + dp[i - 1][j + off][1] * (match(s, i * 2, "BY"))) % mod;
            // PRY +1
            dp[i][j + off][0] = (dp[i][j + off][0] + dp[i - 1][j + off - 1][1] * (match(s, i * 2, "RY"))) % mod;
            // PBP, PRP
            dp[i][j + off][1] = (dp[i][j + off][1] + dp[i - 1][j + off][1] * (match(s, i * 2, "BP") + match(s, i * 2, "RP"))) % mod;
            // YBP
            dp[i][j + off][1] = (dp[i][j + off][1] + dp[i - 1][j + off][0] * (match(s, i * 2, "BP"))) % mod;
            // YRP -1
            dp[i][j + off][1] = (dp[i][j + off][1] + dp[i - 1][j + off + 1][0] * (match(s, i * 2, "RP"))) % mod;
        }
    ans = (ans + dp[N][off][0] + dp[N][off][1]) % mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;

    cin >> N;
    cin >> s;
    if (s[0] == '?')
    {
        s[0] = 'Y';
        solve(s);
        s[0] = 'P';
        solve(s);
    }
    else
        solve(s);
    cout << ans << '\n';
}