#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m;
pii b[1000005];
set<int> s;

signed main()
{
    fast;
    cin >> n;
    n--;
    for (int i = 0; i < n; i++)
    {
        b[i].second = i;
        cin >> b[i].first;
    }
    sort(b, b + n, greater<pll>());
    s.insert(-1);
    s.insert(n);
    for (int i = 0; i < n; i++)
    {
        m += ((ll)b[i].second - *prev(s.upper_bound(b[i].second))) * (*(s.upper_bound(b[i].second)) - (ll)b[i].second) * (ll)b[i].first;
        s.insert(b[i].second);
    }
    cout << m << '\n';
}