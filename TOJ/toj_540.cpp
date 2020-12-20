#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

ll t[200000][3], _dp[200000][3], road, a = 0, b = 0, c = 0, minimum;
bool cal[200000][3] = {{0}};

ll dp(ll index, int type /*0=swim 1=bike 2=run*/)
{
    if (index < type || type < 0)
    {
        return _INFINITY;
    }
    if (index == 0 && type == 0)
    {
        return t[0][0];
    }
    if (cal[index][type] == 0)
    {
        cal[index][type] = 1;
        _dp[index][type] = min(dp(index - 1, type), dp(index - 1, type - 1)) + t[index][type];
    }
    return _dp[index][type];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> road;
    for (int i = 0; i < road; i++)
    {
        cin >> t[i][0] >> t[i][1] >> t[i][2];
    }
    cout << dp(road - 1, 2) << '\n';
}