/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
// #include <bits/stdc++.h>
// #pragma pack(0)
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int t, N;

vector<pii> sol;
vector<int> cur;

void solve(int n, int m)
{
    if (n <= 2)
    {
        for (int i = 1; i <= n; i++)
            cur.emplace_back(i * m);
        return;
    }
    int k = 1 << __lg(n), i = 1;
    cur.emplace_back(m * k);
    for (; k + i <= n; i++)
    {
        sol.emplace_back(pii(m * (k + i), m * (k - i)));
        cur.emplace_back(2 * k * m);
    }
    i--;
    solve(i, m * 2);
    solve(k - i - 1, m);
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        cin >> N;
        if (N == 2)
        {
            cout << -1 << '\n';
            continue;
        }
        cur.clear();
        sol.clear();
        solve(N, 1);
        sort(cur.begin(), cur.end());
        int zero = -1;
        for (int i = 0;; i++)
            if (cur[i] == cur[i + 1] && cur[i] < N)
            {
                sol.emplace_back(pii(cur[i], cur[i]));
                cur[i] = 0, cur[i + 1] = 2 * cur[i + 1];
                zero = i;
                break;
            }
        // for (int i : cur)
        //     cerr << i << ' ';
        // cerr << '\n';
        assert(zero >= 0);
        for (int i = 0; i < cur.size(); i++)
            if (cur[i] > 0)
            {
                while (cur[i] < N)
                {
                    sol.emplace_back(pii(cur[i], 0));
                    sol.emplace_back(pii(cur[i], cur[i]));
                    cur[i] *= 2;
                }
            }
        sol.emplace_back(pii(cur.back(), 0));
        cout << sol.size() << '\n';
        for (auto [x, y] : sol)
            cout << x << ' ' << y << '\n';
    }
}

/*

n = 2
1 2 -> 3 1 -> 4 2
n = 3
1 2 3 -> 4 2 2 -> 4 4 0 -> 4 4 4
n = 4
1 2 3 4 ->
k k k k <- k k k 0
k 0 <- k/2 k/2
k k/2 <- 3k/4 k/4
k k/4 <- 5k/8 3k/8
k/2 k/4 <- 3k/8
n = 5
1 0 8 4 4

n = 9
1 2 3 4 5 6 7 (8) 9


1 3 5 2 4 6
1 2 8 2 4 6
1 4 8 2 4 8


*/