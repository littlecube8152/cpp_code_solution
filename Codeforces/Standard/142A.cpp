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
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;


signed main()
{
    fast;
    ll n, mn = 1e18, mx = 0;
    auto update = [&](ll a, ll b, ll c)
    {
        mn = min(mn, (a + 1) * (b + 2) * (c + 2) - a * b * c);
        mx = max(mx, (a + 1) * (b + 2) * (c + 2) - a * b * c);
    };
   
    cin >> n;
    for (int i = 1; i <= 1000; i++)
        for (int j = i * i; j <= 1000'000; j += i)
            if(n % j == 0)
            {
                int A = n / j, B = j / i, C = i;
                update(A, B, C);
                update(A, C, B);
                update(B, A, C);
                update(B, C, A);
                update(C, A, B);
                update(C, B, A);
            }
    cout << mn << ' ' << mx << '\n';
}
