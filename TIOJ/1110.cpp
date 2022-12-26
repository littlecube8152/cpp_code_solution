/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
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
//using namespace __gnu_pbds;


signed main()
{
    fast;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[26] = {}, mx = 0;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            arr[c - 'a']++;
            mx = max(mx, arr[c - 'a']);
        }
        for (int i = 0; i < 26; i++)
            if(arr[i] == mx)
                cout << (char)(i + 'a');
        cout << '\n';
    }
}
