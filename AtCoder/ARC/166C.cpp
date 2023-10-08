#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

const ll mod = 998244353;

ll fpow(ll b, ll p)
{
    ll a = 1;
    while(p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

const int C = 2000002;
ll T, H, W, f[2000006], mul[2000006];

signed main()
{
    fast;
    f[0] = f[1] = 1;
    for (int i = 2; i <= C; i++)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    mul[0] = 1;
    for (int i = 2; i <= C; i += 2)
        mul[i] = mul[i - 2] * f[i] % mod;
    cin >> T;
    while(T--)
    {
        cin >> H >> W;
        if (H > W)
            swap(H, W);
        ll stair = 2 * H, same = W - H;
        cout << mul[stair] * mul[stair] % mod * fpow(f[2 * H + 1], same) % mod << '\n';
    }
}