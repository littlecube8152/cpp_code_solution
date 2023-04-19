#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1000000007;

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

void solve()
{
    int n;
    cin >> n;
    vector<pll> v(2 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].F >> v[i].S;
        v[i + n] = v[i];
    }
    ll a = 0, b = 0, ans = 0; // ax + by
    for (int i = 1; i < n; i++)
        a = (a + v[i].S * fpow(2, n - 1 - i)) % mod,
        b = (b - v[i].F * fpow(2, n - 1 - i)) % mod;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + a * v[i].F + b * v[i].S) % mod;
        a = (a - v[i + 1].S * fpow(2, n - 2)) % mod,
        b = (b + v[i + 1].F * fpow(2, n - 2)) % mod;
        a = (a + a) % mod,
        b = (b + b) % mod;
        a = (a + v[i + n].S) % mod,
        b = (b - v[i + n].F) % mod;
    }
    cout << (ans + mod) % mod << '\n';
}

// TOi20230415iOT

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}