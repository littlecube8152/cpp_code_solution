#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, K, pre[205][205], res[205][205], ans, cnt;
signed main()
{
    fast;
    ifstream cin("paintbarn.in");
    ofstream cout("paintbarn.out");

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        pre[x1][y1]++;
        pre[x1][y2]--;
        pre[x2][y1]--;
        pre[x2][y2]++;
    }
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            if (pre[i][j] == K)
                pre[i][j] = -1, cnt++;
            else if (pre[i][j] == K - 1)
                pre[i][j] = 1;
            else
                pre[i][j] = 0;
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    for (int t = 1; t <= 2; t++)
    {

        for (int i = 1; i <= 200; i++)
            for (int j = i; j <= 200; j++)
            {
                int cur = 0;
                for (int k = 1; k <= 200; k++)
                {
                    res[i][j] = max(res[i][j], pre[j][k] - pre[i - 1][k] - cur);
                    cur = min(cur, pre[j][k] - pre[i - 1][k]);
                }
            }
        for (int i = 200; i >= 1; i--)
            for (int j = 200; j >= 1; j--)
            {

                if (i <= j)
                    ans = max(ans, res[i][j] + res[j + 1][j + 1]);
                res[i][j] = max({res[i][j], res[i + 1][j], res[i][j + 1]});
            }
        for (int i = 1; i <= 200; i++)
            for (int j = i; j <= 200; j++)
                swap(pre[i][j], pre[j][i]);
        
        for (int i = 1; i <= 200; i++)
            for (int j = 1; j <= 200; j++)
                res[i][j] = 0;
    }

    cout << cnt + ans << '\n';
}