#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

int N, K, pre[1005][1005], ans;
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
    for (int i = 1; i <= 1001; i++)
        for (int j = 1; j <= 1001; j++)
        {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (pre[i][j] == K)
                ans++;
        }
    cout << ans << '\n';
}