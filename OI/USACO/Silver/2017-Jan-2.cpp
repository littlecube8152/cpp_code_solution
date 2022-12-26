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

int n, pre[100005][4], ans;
signed main()
{
    fast;
    ifstream cin("hps.in");
    ofstream cout("hps.out");

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        for (int j = 1; j <= 3; j++)
            pre[i][j] += pre[i - 1][j];
        pre[i][(c == 'H' ? 1 : (c == 'P' ? 2 : 3))]++;
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, max({pre[i][1], pre[i][2], pre[i][3]}) + max({pre[n][1] - pre[i][1], pre[n][2] - pre[i][2], pre[n][3] - pre[i][3]}));
    cout << ans << '\n';
}