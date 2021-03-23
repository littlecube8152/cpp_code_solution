#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, x;

void solve()
{

    ll sum = 0, m = 0;
    while (n--)
    {
        cin >> x;
        m = max(m, x);
        sum += x;
    }
    cout << sum + x + 1 << '\n';
}
int main()
{
    fast;

    while (cin >> n)
        if (n == 0)
            return 0;
        else
            solve();
}