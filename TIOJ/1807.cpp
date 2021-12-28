#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    fast;
    int m, n, x, y;
    map<pair<int, int>, bool> mp;
    cin >> m >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x == y || mp[make_pair(x, y)] || mp[make_pair(y, x)])
        {
            cout << "Yes\n";
            return 0;
        }
        mp[make_pair(x, y)] = 1;
        mp[make_pair(y, x)] = 1;
    }
    cout << "yes\n";
}