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

int n, k, x, cnt;
map<int, int> mp1, mp2;
signed main()
{
    fast;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x % k == 0)
        {
            if (mp2.find(x / k) != mp2.end())
                cnt += mp2[x / k];
            if (mp1.find(x / k) != mp1.end())
                mp2[x] += mp1[x / k];
        }
        mp1[x]++;
    }
    cout << cnt;
}
