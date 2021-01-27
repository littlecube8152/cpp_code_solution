#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll fastpow(ll base, ll power)
{
    if (power == 0)
        return 1;
    else if (power % 2)
        return base * fastpow(base, power - 1) % MOD;
    else
    {
        ll half = fastpow(base, power / 2) % MOD;
        return half * half % MOD;
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        cout << x * (fastpow(2, n) - 1) % MOD << '\n';
    }
    return 0;
}