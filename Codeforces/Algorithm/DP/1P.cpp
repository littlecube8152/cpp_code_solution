/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int n, x, a[100];
signed main()
{
    fast;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] *= (n - i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        x -= a[i];
        if (x < 0)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
}
