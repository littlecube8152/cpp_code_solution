#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    ll m, n, t = 1;
    vector<ll> v;
    cin >> m >> n;

    for (int i = 0; i < m * n; i++)
    {
        ll k;
        cin >> k;
        v.emplace_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < m * n; i++)
    {
        if (v[i] != v[i - 1])
            t++;
    }
    cout << t << '\n';
}