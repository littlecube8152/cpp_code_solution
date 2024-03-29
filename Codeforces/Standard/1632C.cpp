/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

int makesame(int sub, int min)
{
    for (int p = 20; p >= 1; p--)
        if((min & ((1 << p) - 1)) <= (sub & ((1 << p) - 1)))
            return (min & ~((1 << p) - 1)) | (sub & ((1 << p) - 1));
    return min;
}


signed main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, ans = 1e8;
        cin >> a >> b;
        for (int i = a, j = 0; i < b; i++, j++)
            ans = min(ans, makesame(i, b) - b + 1 + j);
        cout << min(ans, b - a) << '\n';
    }
}
