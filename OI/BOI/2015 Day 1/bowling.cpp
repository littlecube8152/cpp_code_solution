#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll dp[10][66][66][331], pre[10][66][331], sum[66][331];
int cost[66][66][66], cost223[66][66][331], cost23[66][331], cost3[331], can[11][331];
const int s2 = 66, s3 = 241;
string mp2[s2], mp3[s3];

int _cost(string s, string t)
{
    int a = -1, b = -1;
    for (auto c : t)
    {
        if (c == 'x')
            (a == -1 ? a : b) = 10;
        else if (c == '/')
            b = 10 - a;
        else if (isdigit(c))
            (a == -1 ? a : b) = c - '0';
        if (b >= 0)
            break;
    }
    a = max(0, a), b = max(0, b);

    if (s[0] == 'x')
        return 10 + a + b;
    else if (s[1] == '/')
        return 10 + a;
    else
        return s[0] + s[1] - 2 * '0';
}

bool match(string s, string t)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i] && s[i] != '?')
            return 0;
    return 1;
}

void solve()
{
    string s;
    int n, ans[13] = {};
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> ans[i + 2];
    dp[0][0][0][0] = 1;

    for (int i = 1; i <= 9; i++)
        for (int j = 0; j < s2; j++)
            for (int k = 0; k < s2; k++)
                for (int sc = 0; sc <= 330; sc++)
                    dp[i][j][k][sc] = 0;

    for (int i = 1; i <= n - 1; i++)
        for (int j = 0; j < s2; j++)
            for (int sc = 0; sc <= 330; sc++)
                pre[i][j][sc] = sum[j][sc] = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        string t = s.substr(2 * i, 2);
        for (int l = 0; l < s2; l++)
            can[i][l] = match(t, mp2[l]);
    }
    for (int i = 0; i <= n - 2; i++)
        for (int j = 0; j < s2; j++)
            for (int k = 0; k < s2; k++)
                if (j == 65 && k == 65)
                {
                    for (int sc = 0; sc <= 330; sc++)
                    {
                        if (i > 0 && can[i - 1][k])
                            dp[i][j][k][sc] += pre[i][j][sc];
                        if (dp[i][j][k][sc] != 0)
                            for (int l = 0; l < s2; l++)
                                if (can[i][l] && (sc + cost[j][k][l] == ans[i + 1] || ans[i + 1] == -1))
                                    dp[i + 1][k][l][sc + cost[j][k][l]] += dp[i][j][k][sc];
                    }
                }
                else
                {
                    int l, r;
                    if (ans[i + 1] == -1)
                        l = 0, r = 330 - cost[j][k][0];
                    else
                        l = max(0, ans[i + 1] - cost[j][k][0]), r = ans[i + 1] - cost[j][k][0];

                    for (int sc = l; sc <= r; sc++)
                    {
                        if (i > 0 && can[i - 1][k])
                            dp[i][j][k][sc] += pre[i][j][sc];
                        pre[i + 1][k][sc + cost[j][k][0]] += dp[i][j][k][sc];
                    }
                }

    ll res = 0;
    for (int l = 0; l < s3; l++)
        can[n - 1][l] = match(s.substr(2 * n - 2, 3), mp3[l]);
    for (int j = 0; j < s2; j++)
        for (int k = 0; k < s2; k++)
            if (j == 65 && k == 65)
            {
                for (int sc = 0; sc <= 330; sc++)
                {
                    if (can[n - 2][k])
                        dp[n - 1][j][k][sc] += pre[n - 1][j][sc];
                    if (dp[n - 1][j][k][sc] != 0)
                        for (int l = 0; l < s3; l++)
                            if (can[n - 1][l])
                            {
                                int an2 = cost223[j][k][l], an1 = an2 + cost23[k][l], an = an1 + cost3[l];
                                if ((sc + an2 == ans[n] || ans[n] == -1) &&
                                    (sc + an1 == ans[n + 1] || ans[n + 1] == -1) &&
                                    (sc + an == ans[n + 2] || ans[n + 2] == -1))
                                    res += dp[n - 1][j][k][sc];
                            }
                }
            }
            else
            {
                for (int sc = 0; sc <= 330 - cost223[j][k][0]; sc++)
                {
                    if (can[n - 2][k])
                        dp[n - 1][j][k][sc] += pre[n - 1][j][sc];
                    if ((sc + cost223[j][k][0] == ans[n] || ans[n] == -1))
                        sum[k][sc + cost223[j][k][0]] += dp[n - 1][j][k][sc];
                    dp[n - 1][j][k][sc] = 0;
                }
            }

    for (int k = 0; k < s2; k++)
        for (int sc = 0; sc <= 330; sc++)
            if (sum[k][sc] != 0)
                for (int l = 0; l < s3; l++)
                    if (can[n - 1][l])
                    {
                        int an1 = cost23[k][l], an = an1 + cost3[l];
                        if ((sc + an1 == ans[n + 1] || ans[n + 1] == -1) &&
                            (sc + an == ans[n + 2] || ans[n + 2] == -1))
                            res += sum[k][sc];
                    }

    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int idx = 0;
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= 10 - i; j++)
        {
            string s = (i == 10 ? "x-" : (i + j == 10 ? string(1, '0' + i) + "/" : string(1, '0' + i) + string(1, '0' + j)));
            mp2[idx] = s;
            idx++;
        }
    idx = 0;
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= (i == 10 ? 10 : 10 - i); j++)
            for (int k = 0; k <= (i == 10 ? (j == 10 ? 10 : 10 - j) : (i + j == 10 ? 10 : 0)); k++)
            {
                string s = (i == 10 ? "x" : string(1, '0' + i)) +
                           (j == 10 ? "x" : string(1, '0' + j)) +
                           (k == 10 ? "x" : string(1, '0' + k));
                if (i < 10 && i + j == 10)
                    s[1] = '/';
                if (i == 10 && j < 10 && j + k == 10)
                    s[2] = '/';
                if (i + j < 10)
                    s[2] = '-';
                mp3[idx] = s;
                idx++;
            }
    for (int j = 0; j < s2; j++)
        for (int k = 0; k < s2; k++)
            for (int l = 0; l < s2; l++)
            {
                cost[j][k][l] = _cost(mp2[j], mp2[k] + mp2[l]);
            }
    for (int j = 0; j < s2; j++)
        for (int k = 0; k < s2; k++)
            for (int l = 0; l < s3; l++)
                cost223[j][k][l] = _cost(mp2[j], mp2[k] + mp3[l]);
    for (int k = 0; k < s2; k++)
        for (int l = 0; l < s3; l++)
            cost23[k][l] = _cost(mp2[k], mp3[l]);
    for (int l = 0; l < s3; l++)
    {
        int &an = cost3[l];

        if (mp3[l][1] == '/')
        {
            an += 10;
            if (mp3[l][2] != '-')
                an += (mp3[l][2] == 'x' ? 10 : mp3[l][2] - '0');
        }
        else
        {
            an += (mp3[l][0] == 'x' ? 10 : mp3[l][0] - '0');
            if (mp3[l][2] == '/')
                an += 10;
            else
            {
                an += (mp3[l][1] == 'x' ? 10 : mp3[l][1] - '0');
                if (mp3[l][2] != '-')
                    an += (mp3[l][2] == 'x' ? 10 : mp3[l][2] - '0');
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
        solve();
}