/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #include <bits/extc++.h>
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const int C = 2'000'000;
ll N, M, Q, val[C + 5], ans[C + 5];

signed main()
{
    fast;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        val[a]++;
    }
    for (int i = 2; i <= C; i++)
    {
        vector<int> v(25, 0);
        int tot = 0;
        for (int j = 0; i * j <= C; j++)
        {
            int rem = M - tot;
            if (0 <= rem && rem < i && i * j + rem <= C)
                ans[i] += val[i * j + rem];
            v[0]++;
            tot++;
            for (int k = 0; v[k] >= i; k++)
            {
                v[k] -= i;
                v[k + 1]++;
                tot -= (i - 1);
            }
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        int b;
        cin >> b;
        if(b > C)
            cout << (M <= C ? val[M] : 0) << '\n';
        else
            cout << ans[b] << '\n';
    }
}
