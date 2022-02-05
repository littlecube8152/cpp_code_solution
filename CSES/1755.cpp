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

char haso = 0;
map<char, int> mp;
signed main()
{
    fast;
    string s, t;
    cin >> s;
    for (char c : s)
        mp[c]++;
    for (auto i : mp)
        if (i.S % 2 && haso != 0)
        {
            cout << "NO SOLUTION";
            return 0;
        }
        else if (i.S % 2)
            haso = i.F;
    for (auto i : mp)
        if (i.S % 2 == 0)
            t += string(i.S / 2, i.F);
    for (int i = 0; i < t.size(); i++)
        cout << t[i];
    if (haso != 0)
        cout << string(mp[haso], haso);
    for (int i = t.size() - 1; i >= 0; i--)
        cout << t[i];
}