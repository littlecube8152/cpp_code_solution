#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k;

void solve()
{
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (i == n - k + 1)
            cout << s << '\n';
    }
}
int main()
{
    fast;
    while (cin >> n >> k)
        solve();
}