#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, M, t[50], r = 0, sumt = 0;
pair<ll, ll> dp[50][50][50];
bool comp(ll a, ll b)
{
    return a > b;
}

int main()
{
    fast;

    cin >> n >> k >> M;
    for (int i = 1; i <= k; i++)
    {
        cin >> t[i];
        sumt += t[i];
    }
    //sort(t + 1, t + k + 1);
    for (int l = 0; l <= n; l++)
    {
        if (M <= 0)
            break;

        for (int i = 0; i <= n - l; i++)
            dp[l][i][0] = make_pair(l * (k + 1), M);
        for (int j = 0; j <= k; j++)
            dp[l][0][j] = make_pair(l * (k + 1), M);

        for (int j = 1; j <= k; j++)
            for (int i = 0; i <= n - l; i++)
            {
                for (int m = 0; m <= n - l; m++)
                    if (dp[l][m][j - 1].second >= i * t[j])
                        dp[l][i][j] = max(dp[l][i][j], make_pair(dp[l][m][j - 1].first + i, dp[l][m][j - 1].second - i * t[j]));
                if (i != 0)
                    if (dp[l][i - 1][j].second >= t[j])
                        dp[l][i][j] = max(dp[l][i - 1][j], make_pair(dp[l][i - 1][j].first + 1, dp[l][i - 1][j].second - t[j]));
            }
        M -= sumt;
    }
    for (int l = 0; l <= n; l++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
            {
                r = max(r, dp[l][i][j].first);
                //cout << dp[l][i][j].first << "," << dp[l][i][j].second << "   ";
                //cout << " \n"[j == k];
            }

    cout << r;
    return 0;
}