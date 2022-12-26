#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
ll N, spi[1000006], pi[1000006];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        pi[i] = (pi[i - 1] * (1 + a) + a) % mod;
        spi[i] = (spi[i - 1] * (1 + a) + pi[i - 1] * a + a) % mod;
    }
    cout << spi[N] << '\n';
}