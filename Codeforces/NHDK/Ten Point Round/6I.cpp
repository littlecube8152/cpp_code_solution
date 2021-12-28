#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int _f[100] = {0};

int f(int n)
{
    if (n % 2)
        return (1 << (n - 1)) % MOD;
    if (n == 0)
        return 1;
    else if (!_f[n])
        _f[n] = f(n - 2) * (n / 2 + 1) % MOD;
    return _f[n];
}

signed main()
{
    int q;
    cin >> q;
    while (q--)
    {
        ll n, k, AND, OR, XOR, r = 1;
        cin >> n >> k;
        AND = (1 << k) - 1;
        OR = 0;
        XOR = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            AND &= x;
            OR |= x;
            XOR ^= x;
        }
        for (ll i = 0; i < k; i++)
        {
            if (OR & 1 && XOR & 1 && !(AND & 1))
                r = r * ((1 << (n)) - f(n) - (n % 2 == 0)) % MOD;
            if (OR & 1 && !(XOR & 1) && !(AND & 1))
                r = r * (f(n) - (n % 2 == 0)) % MOD;
            AND = AND >> 1;
            OR = OR >> 1;
            XOR = XOR >> 1;
        }
        cout << r << '\n';
    }
}