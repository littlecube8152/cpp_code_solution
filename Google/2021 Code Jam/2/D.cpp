/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, r, c, f, s;
char a[20][20], b[20][20];

signed main()
{
    fast;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cin >> r >> c >> f >> s;
        int ans = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> a[i][j];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c;j++)
                cin >> b[i][j];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c;j++)
                if(a[i][j] != b[i][j])
    }
}
