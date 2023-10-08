#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
ll n, s, l[100005], ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    if(n == 1)
    {
        s += l[1] + 2;
        cout << (s - 1) * 2 % mod << '\n';
        return 0;
    }
    // stem
    ans += s;
    // include H + stem but not T
    ll mul = 1;
    for (int i = 1; i <= n; i++)
        mul = mul * (l[i] + 1) % mod;
    ans = (ans + mul) % mod;
    // inside each chain
    for (int i = 1; i <= n; i++)
        ans = (ans + l[i] * (l[i] + 1) / 2) % mod;
    cout << ans * 2 % mod << '\n';
}