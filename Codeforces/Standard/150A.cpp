#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll q;
    cin >> q;

    vector<ll> d;
    for (ll i = 2; i * i <= q; i++)
        while (q % i == 0)
        {
            q /= i;
            d.emplace_back(i);
        }
    
    if (q != 1)
        d.emplace_back(q);

    if (d.size() == 2)
        cout << 2 << '\n';
    else
    {
        if (d.size() <= 1)
            cout << 1 << '\n'
                 << 0 << '\n';
        else
            cout << 1 << '\n'
                 << d[0] * d[1] << '\n';
    }
}