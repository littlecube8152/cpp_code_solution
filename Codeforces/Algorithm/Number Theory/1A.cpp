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
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, a[100005], suma[100005] = {0};
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        suma[0] = a[0];
        for (int i = 1; i < n; i++)
            suma[i] = suma[i - 1] + a[i];
        int index = upper_bound(a, a + n, x) - a;
        index--;
        if (index >= 0)
            cout << ((ll)x * (x + 1LL) / 2LL) - (ll)suma[index] * 2LL << '\n';
        else
            cout << ((ll)x * (x + 1LL) / 2LL) << '\n';
    }
    return 0;
}