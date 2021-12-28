//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

char arr[505][505];
int n;
unordered_map<int, int> dp;
int hsh(int a, int b, int c, int d)
{
    return 216000000 * a + 360000 * b + 600 * c + d;
}

signed main()
{
    //fast;
    //ifstream cin("palpath.in");
    //ofstream cout("palpath.out");
    cin >> n;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        dp[hsh(i, n + 1 - i, i, n + 1 - i)] = 1;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= n - i; j++)
            for (int k = i + 1; k <= n; k++)
            {
               
            }
    cout << dp[hsh(1, 1, n, n)] << '\n';
}