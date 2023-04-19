/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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

int n, k;

int getnum(int x, int y, int n)
{
    int center = (n + 1) / 2;
    int layer = max({x - center, center - x, y - center, center - y});
    int ans = n * n - (2 * layer + 1) * (2 * layer + 1);
    if (center - x == layer)
        ans += y - center + layer + 1;
    else if (y - center == layer)
        ans += x - center + 3 * layer + 1;
    else if (x - center == layer)
        ans += (center - y) + 5 * layer + 1;
    else
        ans += (center - x) + 7 * layer + 1;
    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        vector<pii> soln;

        cin >> n >> k;
        k = n * n - 1 - k;
        int x = 1, y = 1;
        for (int i = 1; i < n * n;)
        {
            int jmp = 1e9;
            pii jd, nd;
            for (auto [dx, dy] : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
                if (1 <= x + dx && x + dx <= n &&
                    1 <= y + dy && y + dy <= n)
                {
                    if (getnum(x + dx, y + dy, n) == i + 1)
                        nd = pii(dx, dy);
                    else if (getnum(x + dx, y + dy, n) > i)
                        jmp = getnum(x + dx, y + dy, n), jd = pii(dx, dy);
                }
            if (k >= jmp - i - 1)
            {
                k -= jmp - i - 1;
                soln.emplace_back(pii(i, jmp));
                i = jmp;
                x += jd.F, y += jd.S;
            }
            else
            {
                i++;
                x += nd.F, y += nd.S;
            }
        }
        if (k)
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        else
        {
            cout << "Case #" << t << ": " << soln.size() << '\n';
            for (auto [i, j] : soln)
                cout << i << " " << j << '\n';
        }
    }
}