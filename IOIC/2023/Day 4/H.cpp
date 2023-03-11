#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

ll n, m, a, c, tot, ans;

signed main()
{
    cin >> n >> ans;
    tot = ans;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        tot += a;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> c;
        ans = (ans + ans * inv(tot) % mod * c) % mod;
        tot = (tot + c) % mod;
    }
    cout << ans << '\n';
}