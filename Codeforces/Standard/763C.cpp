/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll fpow(ll b, ll p, ll m)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return a;
}

ll inv(ll b, ll m)
{
    return fpow(b, m - 2, m);
}

// assume 2n < m
pii solve(int n, ll m, vector<int> a)
{
    if (n == 1)
        return pii(a[0], 1);
    if (n == 0)
        return pii(1, 1);

    ll d = (a[1] - a[0] + m) % m;

    map<ll, int> mp;
    for (auto i : a)
        mp[i]++;
    ll k = 0;
    for (auto i : a)
        k += (mp[(i + d) % m]);
    cerr << d << " appears " << k << '\n';
    k = n - k;
    if (k == 0)
        return pii(-1, -1);
    d = d * inv(k, m) % m;

    int match = 1;
    {
        ll i = 1;
        while (mp[(a[0] + d * i) % m])
            i++;
        i--;
        match += i;
    }
    {
        ll i = 1;
        while (mp[((a[0] - d * i) % m + m) % m])
            i++;
        i--;
        match += i;
    }
    if (match != n)
        return pii(-1, -1);

    ll start = a[0];
    while (mp[(start - d + m) % m])
        start = (start - d + m) % m;
    return pii(start, d);
}

signed main()
{
    fast;
    ll n, m;
    cin >> m >> n;
    if (2 * n > m)
    {

        map<int, int> mp;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            mp[c] = 1;
        }
        for (int i = 0; i < m; i++)
            if (!mp[i])
                a.emplace_back(i);
        pii ans = solve(m - n, m, a);
        if (ans.F < 0)
            cout << ans.F << '\n';
        else
            cout << (ans.F + (m - n) * ans.S) % m << ' ' << ans.S << '\n';
    }
    else
    {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        pii ans = solve(n, m, a);
        if (ans.F < 0)
            cout << ans.F << '\n';
        else
            cout << ans.F << ' ' << ans.S << '\n';
    }
}
