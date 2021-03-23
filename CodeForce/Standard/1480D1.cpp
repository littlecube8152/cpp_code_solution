#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int n, dp[100005][2], a[100005];
set<pii> putdp[100005][2];
signed main()
{
    fast;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    putdp[0][0].insert(make_pair(0, 0));
    putdp[0][1].insert(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        for (pii j : putdp[i - 1][0])
            if (j.first != a[i])
            {
                if (dp[i - 1][0] + 1 > dp[i][0])
                {
                    dp[i][0] = dp[i - 1][0] + 1;
                    putdp[i][0].clear();
                    putdp[i][0].insert(make_pair(a[i], j.second));
                }
                else if (dp[i - 1][0] + 1 == dp[i][0])
                    putdp[i][0].insert(make_pair(a[i], j.second));
            }
            else
            {
                if (dp[i - 1][0] > dp[i][0])
                {
                    dp[i][0] = dp[i - 1][0];
                    putdp[i][0].clear();
                    putdp[i][0].insert(make_pair(a[i], j.second));
                }
                else if (dp[i - 1][0] == dp[i][0])
                    putdp[i][0].insert(make_pair(a[i], j.second));
            }
        for (pii j : putdp[i - 1][1])
            if (j.first != a[i])
            {
                if (dp[i - 1][1] + 1 > dp[i][0])
                {
                    dp[i][0] = dp[i - 1][1] + 1;
                    putdp[i][0].clear();
                    putdp[i][0].insert(make_pair(a[i], j.second));
                }
                else if (dp[i - 1][1] + 1 == dp[i][0])
                    putdp[i][0].insert(make_pair(a[i], j.second));
            }
            else
            {
                if (dp[i - 1][1] > dp[i][0])
                {
                    dp[i][0] = dp[i - 1][1];
                    putdp[i][0].clear();
                    putdp[i][0].insert(make_pair(a[i], j.second));
                }
                else if (dp[i - 1][1] == dp[i][0])
                    putdp[i][0].insert(make_pair(a[i], j.second));
            }
        for (pii j : putdp[i - 1][0])
            if (j.second != a[i])
            {
                if (dp[i - 1][0] + 1 > dp[i][1])
                {
                    dp[i][1] = dp[i - 1][0] + 1;
                    putdp[i][1].clear();
                    putdp[i][1].insert(make_pair(j.first, a[i]));
                }
                else if (dp[i - 1][0] + 1 == dp[i][1])
                    putdp[i][1].insert(make_pair(j.first, a[i]));
            }
            else
            {
                if (dp[i - 1][0] > dp[i][1])
                {
                    dp[i][1] = dp[i - 1][0];
                    putdp[i][1].clear();
                    putdp[i][1].insert(make_pair(j.first, a[i]));
                }
                else if (dp[i - 1][0] == dp[i][1])
                    putdp[i][1].insert(make_pair(j.first, a[i]));
            }
        for (pii j : putdp[i - 1][1])
            if (j.second != a[i])
            {
                if (dp[i - 1][1] + 1 > dp[i][1])
                {
                    dp[i][1] = dp[i - 1][1] + 1;
                    putdp[i][1].clear();
                    putdp[i][1].insert(make_pair(j.first, a[i]));
                }
                else if (dp[i - 1][1] + 1 == dp[i][1])
                    putdp[i][1].insert(make_pair(j.first, a[i]));
            }
            else
            {
                if (dp[i - 1][1] > dp[i][1])
                {
                    dp[i][1] = dp[i - 1][1];
                    putdp[i][1].clear();
                    putdp[i][1].insert(make_pair(j.first, a[i]));
                }
                else if (dp[i - 1][1] == dp[i][1])
                    putdp[i][1].insert(make_pair(j.first, a[i]));
            }
        if(i >= 2)
        {
            putdp[i - 2][0].clear();
            putdp[i - 2][1].clear();
        }
    }
    cout << max(dp[n][0], dp[n][1]);
}