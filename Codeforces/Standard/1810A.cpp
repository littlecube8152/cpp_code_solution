/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;


signed main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        int n, a;
        bool ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if(a <= i)
                ans = 1;
        }
        cout << (ans ? "Yes\n" : "No\n");
    }
}
