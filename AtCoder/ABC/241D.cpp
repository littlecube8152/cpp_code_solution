/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int Q, c, x, k;
signed main()
{
    fast;
    multiset<ll, greater<ll>> two;
    multiset<ll> three;
    cin >> Q;
    for (int i = 1; i <= 6; i++)
    {
        two.insert(-1);
        three.insert(2e18);
    }
    for (int i = 1; i <= Q; i++)
    {
        cin >> c >> x;
        if (c == 1)
        {
            two.insert(x);
            three.insert(x);
        }
        else if (c == 2)
        {
            cin >> k;
            auto iter = two.lower_bound(x);
            for (int i = 1; i < k; i++)
                ++iter;
            cout << *iter << '\n';
        }
        else if (c == 3)
        {
            cin >> k;
            auto iter = three.lower_bound(x);
            for (int i = 1; i < k; i++)
                ++iter;
            cout << (*iter > 1e18 ? -1 : *iter) << '\n';
        }
    }
}
