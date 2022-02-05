#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dp[3005][3005];
pii predp[3005][3005];
bool cdp[3005][3005];
string a, b;

int DP(int i, int j)
{
    if (i <= 0 || j <= 0)
        return 0;
    if (!cdp[i][j])
    {
        cdp[i][j] = 1;
        if (a[i - 1] == b[j - 1])
            dp[i][j] = DP(i - 1, j - 1) + 1, predp[i][j] = make_pair(i - 1, j - 1);
        else
        {
            int x = DP(i - 1, j), y = DP(i, j - 1);
            if (x > y)
                dp[i][j] = x, predp[i][j] = make_pair(i - 1, j);
            else
                dp[i][j] = y, predp[i][j] = make_pair(i, j - 1);
        }
    }
    return dp[i][j];
}

signed main()
{
    cin >> a >> b;
    int k = DP(a.length(), b.length()), i = a.length(), j = b.length();
    string s;
    while (i != 0 && j != 0)
    {

        if (a[i - 1] == b[j - 1])
            s = a[i - 1] + s;
        tie(i, j) = tie(predp[i][j].F, predp[i][j].S);
    }
    cout << s << '\n';
}