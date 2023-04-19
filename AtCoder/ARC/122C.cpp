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

ll fib[90], N, bit[90];

signed main()
{
    // fast;
    fib[1] = 1;
    for (int i = 2; i <= 87; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    cin >> N;
    int layer = 0;
    for (int i = 87; i >= 1; i--)
        if (N >= fib[i])
        {
            bit[i] = 1;
            N -= fib[i];
            layer = max(layer, i);
        }
    vector<int> op;
    for (int i = layer; i >= 1; i--)
    {
        if ((layer - i) % 2)
        {
            if (i < layer)
                op.emplace_back(3);
            if (bit[layer - i + 1])
                op.emplace_back(2);
        }
        else
        {
            if (i < layer)
                op.emplace_back(4);
            if (bit[layer - i + 1])
                op.emplace_back(1);
        }
    }
    reverse(op.begin(), op.end());
    cout << op.size() << '\n';
    for (int i : op)
        cout << i << '\n';
}
