#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, d;
        cin >> a >> b;
        ll g = __gcd(a, b);
        a /= g, b /= g;
        if (a == 1 && b == 1)
        {
            cout << 2 << ' ' << 2 << '\n';
            continue;
        }
        if (a == 2)
        {
            cout << b << ' ' << b << '\n';
            continue;
        }
        ll L = 1, R = a / 2;
        while (L < R)
        {
            ll mid = (L + R + 1) / 2;
            if ((a - mid) * mid <= b)
                L = mid;
            else
                R = mid - 1;
        }
        cout << L << ' ' << b / L << '\n';
    }
}