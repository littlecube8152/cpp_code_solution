#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define _INFINITY 9223372036854775807
using namespace std;

ll n, a[1000005], ans;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll p = 1;
    for (int i = n-1; i >= 1; i--)
        {
            ans = (ans + ((p * 2) + (p * (n - i) % MOD)) * a[i]) % MOD;
            p = p * 2 % MOD;
            //cout << i << " is " << ((p * 2 % MOD) + (p * (n - i) % MOD)) << '\n';
        }
        cout << ans + a[n];
}