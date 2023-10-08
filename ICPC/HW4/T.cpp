#include <bits/stdc++.h>
#define ll long long
using namespace std;

void extgcd(ll a, ll b, ll c, ll &x, ll &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        extgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}

ll inv(ll b, ll mod)
{
    // b * inv + mod * k = 1
    ll res, _;
    extgcd(b, mod, 1, res, _);
    res = (res + mod) % mod;
    return res;
}

ll dlog(ll X, ll Y, ll M)
{
    ll cur = 1 % M;
    const int K = 31, B = max(5, (int)sqrt(M));

    for (int i = 0; i < K; i++, cur = cur * X % M)
        if (cur == Y)
            return i;

    ll g = gcd(cur, M);
    if (gcd(Y, M) != g)
        return -1;
    cur /= g, M /= g, Y /= g;
    Y = Y * inv(cur, M) % M;
    map<ll, int> mp;
    ll prod = 1;
    for (int i = 0; i < B; i++)
    {
        if (prod % M == Y)
            return K + i;
        mp[prod] = i;
        prod = prod * X % M;
    }
    cur = 1 % M;
    for (int i = 0; B * i <= M + B; i++)
    {
        ll attempt = Y * inv(cur, M) % M;
        if (mp.find(attempt) != mp.end())
            return K + i * B + mp[attempt];
        cur = cur * prod % M;
    }
    return -1;
}

signed main()
{
    ll T, X, Y, M;
    cin >> T;
    while (T--)
    {
        cin >> X >> Y >> M;
        cout << dlog(X, Y, M) << '\n';
    }
}