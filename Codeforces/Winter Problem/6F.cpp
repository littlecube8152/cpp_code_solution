#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
            cout << 0 << '\n';
        else
        {
            ll k = ceil((1.0 + 2 * n - sqrt(4.0 * n + 1.0 + 4.0 * n)) / 2.0);
            assert(k >= 0 && k <= n);
            if (k - 1 >= (n - k) * (n - k + 1) / 2)
                cout << k - 1 + (n - k) * (n - k + 1) / 2 << '\n';
            else
                cout << k + (n - k - 1) * (n - k) / 2 << '\n';
        }
    }
}