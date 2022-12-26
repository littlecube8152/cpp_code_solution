/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int N, Q, l[100005], r[100005], v;
map<int, ll> mp;

signed main()
{
    fast;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> l[0] >> r[0] >> v;
        mp[l[0]] += v;
        mp[r[0]] -= v;
    }
    for (int i = 1; i <= Q; i++)
    {
        cin >> l[i] >> r[i];
        mp[--r[i]] += 0;
        mp[--l[i]] += 0;
    }
    int pre = -1;
    ll cur = 0, acc = 0;
    for(auto &[pos, val] : mp)
    {
        val += acc;
        acc = val;
    }
    acc = 0;
    for(auto &[pos, val] : mp)
    {
        acc += (pos - pre) * cur;
        pre = pos;
        cur = val;
        val += acc;
    }
    for (int i = 1; i <= Q; i++)
        cout << mp[r[i]] - mp[l[i]] << '\n';
}