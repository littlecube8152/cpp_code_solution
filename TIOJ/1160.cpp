#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

map<int, int> mp;

signed main()
{
    fast;
    int n, a = 0, b = 0;
    while (cin >> n)
    {
        if(n == 0)
            return 0;
        mp[n]++;
        if(mp[n] > a)
        {
            a = mp[n];
            b = n;
        }
        if(mp[n] == a && n < b)
            b = n;
        cout << a << " " << b << '\n';
    }
}