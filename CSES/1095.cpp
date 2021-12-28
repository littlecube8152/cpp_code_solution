#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, a, b, c;

ll fast_pow(ll base, ll p, ll mod){
    ll ans = 1, m = base;
    while(p){
        if(p&1)
            ans = ans * m % mod;
        m = m * m % mod;
        p >>= 1;
    }
    return ans;
}

signed main()
{
    fast;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << fast_pow(a, b, MOD) << '\n';
    }
}