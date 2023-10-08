#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
ll n, inv[1000006];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 2; i <= n; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
    for (int i = 1; i < n; i++)
        cout << inv[i + 1] * i % mod << ' ';
    cout << 0 << '\n';
}