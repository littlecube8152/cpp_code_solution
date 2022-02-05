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

vector<int> a, b;
int n, k;
signed main()
{
    //fast;
    cin >> n;
    k = n * (n + 1) / 2;
    if(k % 2)
    {
        cout << "NO\n";
        return 0;
    }
    k /= 2;
    for (int i = n; i >= 1; i--)
        if (k >= i)
        {
            k -= i;
            a.pb(i);
        }
        else
            b.pb(i);
    if (k == 0)
    {
        cout << "YES\n";
        cout << a.size() << '\n';
        for(int i : a)
            cout << i << " ";
        cout << '\n';
        cout << b.size() << '\n';
        for(int i : b)
            cout << i << " ";
        cout << '\n';
    }
    else
        cout << "NO\n";
}