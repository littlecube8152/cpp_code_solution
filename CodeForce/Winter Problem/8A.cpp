#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    fast;
    ll a, b, u, v, x, y;
    cin >> a >> b >> u >> v >> x >> y;
    if ((u - a) * (u - a) + (v - b) * (v - b) == (x - u) * (x - u) + (y - v) * (y - v) && (u - a) * (y - v) != (x - u) * (v - b))
        cout << "Yes\n";
        else
            cout << "No\n";
        return 0;
}