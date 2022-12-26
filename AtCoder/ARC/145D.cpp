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
#define MOD 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m;

vector<int> construct(int n)
{
    if (n == 1)
        return {1};
    vector<int> sub = construct((n + 1) / 2);
    int c = sub.back();
    vector<int> ans = sub;
    for (int i : sub)
        ans.emplace_back(i + 2 * c);
    if (n & 1)
        ans.pop_back();
    return ans;
}

signed main()
{
    fast;
    cin >> n >> m;
    if (n == 1)
    {
        cout << m << '\n';
        return 0;
    }
    vector<int> sol = construct(n - 1);
    m -= 8000000;
    for (int i : sol)
        m -= i;
    int glob = m / (n - 1);
    for (int &i : sol)
        i += glob, m -= glob;

    for (int i : sol)
        cout << i << ' ';
    cout << 8000000 + m << '\n';
}
