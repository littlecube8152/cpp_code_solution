/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;


signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        const int off = 300;
        int R, paint[600][600] = {};
        int ans = 0;
        cin >> R;
        for (int r = 0; r <= R; r++)
            for (int x = -r; x <= r; x++)
            {
                int y = round(sqrt(r * r - x * x));
                paint[300 + x][300 + y] = 1;
                paint[300 + x][300 - y] = 1;
                paint[300 + y][300 + x] = 1;
                paint[300 - y][300 + x] = 1;
            }
        for (int x = -R; x <= R; x++)
            for (int y = -R; y <= R; y++)
                if (round(sqrt(x * x + y * y)) <= R)
                    if (paint[300 + x][300 + y] == 0)
                        ans++;
                        
        cout << "Case #" << t << ": " << ans << '\n';
    }
}