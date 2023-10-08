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
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int T;
    ll A, B, C;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> A >> B >> C;
        // if any single was bought, the answer is the number of patties.
        // otherwise the answer is the number of buns - 1.
        ll ans = 0;
        ans = max(ans, C / A);
        if(C >= A)
            ans = max(ans, 1 + (C - A) / B * 2);
        if(C >= 2 * A)
            ans = max(ans, 2 + (C - 2 * A) / B * 2);
        ans = max(ans, C / B * 2 - 1);
        cout << "Case #" << t << ": " << ans << '\n';
    }
}