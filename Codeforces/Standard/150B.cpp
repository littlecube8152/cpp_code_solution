#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1'000'000'007;
ll n, m, k;
ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    if (k == n)
        cout << fpow(m, (n + 1) / 2) << '\n';
    else if(k > n || k == 1)
        cout << fpow(m, n) << '\n';
    else 
    {
        if (k % 2 == 1)
            cout << m * m % mod << '\n';
        else
            cout << m % mod << '\n';
    }
}