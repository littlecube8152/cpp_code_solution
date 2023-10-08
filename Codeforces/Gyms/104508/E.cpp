#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    ll n, ans, x, y;
    map<pii, ll> pos;
    map<ll, ll> X, Y;
    cin >> n;
    ans = n * (n - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        ans += pos[pii(x, y)];
        ans -= X[x];
        ans -= Y[y];
        pos[pii(x, y)]++;
        X[x]++;
        Y[y]++;
    }
    cout << ans << '\n';
}