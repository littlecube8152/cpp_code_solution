#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    ll n, q;
    map<ll, ll> m;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << m[x] << '\n';
    }
}