#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, v[9950005];

void solve()
{
    cin >> n;
    if (t == 0)
        assert( n < 9950005);
    if (n > 9950005)
    {
        cin.ignore(n * 10, '\n');

        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v, v + n);

    for (int i = 0; i < n - 2; i++)
        if (v[i] + v[i + 1] > v[i + 2])
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

signed main()
{
    fast;

    cin >> t;
    while (t--)
        solve();
}