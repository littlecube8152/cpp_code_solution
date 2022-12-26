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

signed main()
{
    // fast;
    int t;
    cin >> t;
    vector<int> v;
    vector<int> u;

    for (int i = 1; i <= 1e9; i *= 2)
        v.emplace_back(i);

    for (int i = 1e9; v.size() < 100; i--)
        v.emplace_back(i);

    sort(v.begin(), v.end());

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 100; i++)
            cout << v[i] << " \n"[i == 99];
        cout << flush;
        u = v;
        for (int i = 1; i <= 100; i++)
        {
            int j;
            cin >> j;
            u.emplace_back(j);
        }
        sort(u.begin(), u.end(), greater<>());
        ll sum = 0;
        for (int j : u)
            sum += j;
        sum /= 2;
        for (int j : u)
            if (sum >= j)
            {
                sum -= j;
                cout << j << " ";
            }
        cout << endl;
    }
}