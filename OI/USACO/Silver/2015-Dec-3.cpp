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

int n, m, pre[100005][4];

signed main()
{
    fast;
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pre[i][1] += pre[i - 1][1] + (a == 1);
        pre[i][2] += pre[i - 1][2] + (a == 2);
        pre[i][3] += pre[i - 1][3] + (a == 3);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << pre[r][1] - pre[l - 1][1] << " " << pre[r][2] - pre[l - 1][2] << " " << pre[r][3] - pre[l - 1][3] << "\n";
    }
}