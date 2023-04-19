/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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
// using namespace __gnu_pbds;

int N, p[505];

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    vector<int> ops;
    bool parity = 0;

    auto op = [&](int pos)
    {
        ops.emplace_back(pos);
        swap(p[pos], p[pos + 1]);
    };

    int i = 1;
    for (; i < N; i++)
    {
        int pos = i;
        for (; pos <= N; pos++)
            if (p[pos] == i)
                break;

        if (pos == i)
            continue;

        if (pos % 2 != parity)
            for (int j = i + 1; j <= N; j++)
                if (j % 2 == parity && p[j] != i && p[j - 1] != i)
                {
                    op(j - 1);
                    parity ^= 1;
                    break;
                }
        if (pos % 2 != parity)
        {
            if (pos == N)
            {
                op(pos - 2);
                op(pos - 1);
                op(pos - 2);
                op(pos - 1);
                op(pos - 2);
                continue;
            }
            else
            {
                op(pos);
                op(pos - 1);
                pos++;
            }
        }
        for (int j = pos; j > i; j--)
        {
            ops.emplace_back(j - 1);
            swap(p[j - 1], p[j]);
            parity ^= 1;
        }
    }
    for (int i = 1; i <= N; i++)
        if (p[i] != i)
            assert(false);

    int k = ops.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << ops[i] << " \n"[i == k - 1];
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
        solve();
}
