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

int t;

bool check(int a, int b, int U, int u[1001])
{
    int v[1001] = {0};
    v[U] = 1;
    for (int i = 1000; i >= 1; i--)
    {
        v[i] -= u[i];
        if (v[i] < 0)
            return 0;
        if (i - a >= 1)
            v[i - a] += v[i];
        if (i - b >= 1)
            v[i - b] += v[i];
        v[i] = 0;
    }
    return 1;
}

signed main()
{
    fast;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n, a, b, u[1001] = {0};
        bool bo = 0;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
            cin >> u[i];
        for (int j = n; j <= 1000; j++)
            if (check(a, b, j, u))
            {
                cout << "Case #" << i << ": " << j << '\n';
                bo = 1;
                break;
            }
        if (!bo)
            cout << "Case #" << i << ": IMPOSSIBLE\n";
    }
}
