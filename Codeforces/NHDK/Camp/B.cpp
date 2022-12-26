/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, a[8], b[8], c[8], d[8], s[8];
bool used[8];

pll brute(ll cur, ll sat, ll rest, ll de)
{
    if (cur == n)
    {
        // for(int i : v)
        //     cerr << i << ' ';
        // cerr << "= " << rest << " " << de << '\n';
        return {-rest, de};
    }
    else
    {
        pll opt = {-48763, 0};
        for (int i = 0; i < n; i++)
            if (!used[i])
            {
                used[i] = 1;
                if (sat + s[i] > m)
                {
                    assert(false);
                    opt = max(opt, brute(cur + 1, s[i], rest + 1, de + d[i] * (cur + 1)));
                }
                else
                    opt = max(opt, brute(cur + 1, sat + s[i], rest, de + d[i] * (cur + 1)));
                used[i] = 0;
            }
        return opt;
    }
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        d[i] = abs(a[i] - b[i]) + abs(b[i] - c[i]) + abs(a[i] - c[i]);
        s[i] = a[i] + b[i] + c[i];
    }
    pll ans = brute(0, 0, 0, 0);
    cout << -ans.F << ' ' << ans.S << '\n';
}
