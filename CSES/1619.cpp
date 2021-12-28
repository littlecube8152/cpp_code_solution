/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int n, k, m;
vector<pii> v;
signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb((pii{x, 1}));
        v.pb((pii{y, -1}));
    }
    sort(v.begin(), v.end());
    for(auto i : v)
    {
        k += i.S;
        m = max(m, k);
    }
    cout << m;
}