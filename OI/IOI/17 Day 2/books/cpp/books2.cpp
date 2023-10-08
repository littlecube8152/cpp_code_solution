#pragma GCC optimize("Ofast,unroll-loops")
#include "books.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, dp[1005][1005], rp[1005], l, r, range[1005][2];

long long minimum_walk(std::vector<int> p, int s)
{
    n = p.size();
    l = 0, r = n - 1;
    while (l < n && p[l] == l)
        l++;
    if (l == n)
        return 0;
    while (r && p[r] == r)
        r--;

    ll ans = 0;
    if (s < l)
    {
        ans += 2 * (l - s);
        s = l;
    }
    if (r < s)
    {
        ans += 2 * (s - r);
        s = r;
    }
    for (int i = 0; i < n; i++)
        ans += abs(p[i] - i);
    for (int i = 0; i < n; i++)
        rp[p[i]] = i;

    cerr << "calc n\n";
    // calc n

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 1e9;
    dp[s][s] = 0;
    for (int i = 0; i < n; i++)
        range[i][0] = min({i, p[i], rp[i]}), range[i][1] = max({i, p[i], rp[i]});
    for (int l = 0; l < n; l++)
        for (int i = 0; i + l < n; i++)
        {
            int j = i + l;
            for (int k = i; k <= j; k++)
            {
                dp[min(i, range[k][0])][max(j, range[k][1])] = min(dp[min(i, range[k][0])][max(j, range[k][1])], dp[i][j]);
                if (j + 1 < n)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 2);
                if (i)
                    dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + 2);
            }
        }
    // for (int i = 0; i < n; i++)
    // 	for (int j = i; j < n; j++)
    // 		cerr << dp[i][j] << " \n"[j == n - 1];
    return ans + dp[l][r];
}