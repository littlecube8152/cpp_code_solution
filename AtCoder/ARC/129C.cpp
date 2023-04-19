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

ll N, cur;
vector<int> v;

signed main()
{
    fast;
    cin >> N;
    while (N > 0)
    {
        int i = 1;
        for (; i <= 1e6; i++)
        {
            if (i * (i + 1) / 2 > N)
            {
                i--;
                break;
            }
        }
        v.emplace_back(i);
        N -= i * (i + 1) / 2;
    }
    int k = 1;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            cout << '7';
            k = (k * 10) % 7;
        }
        cout << k;
    }
    cout << string(v.back(), '7') << '\n';
}
