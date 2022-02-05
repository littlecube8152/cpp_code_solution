#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return max(a, b);
    else
    {
        while (b != 0)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a[100005] = {0}, m = 1, ml = 2;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n - 1; i++)
        {
            ll g = gcd(a[i], a[i + 1]);
            m = max(m, g);
        }
        ll g = a[0], oldi = 0;
        for (ll i = 1; i < n; i++)
        {
            g = gcd(g, a[i]);
            if (g == m)
                ml = max(ml, i - oldi + 1);
            else
            {
                g = a[i];
                oldi = i;
            }
        }
        cout << m << " " << ml << '\n';
    }
    return 0;
}