#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;

ll N, D, ans = 1;


signed main()
{
    cin >> N >> D;
    assert(N == 2);
    ll p = D % (MOD - 1), b = 4;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % MOD;
        p >>= 1;
        b = b * b % MOD;
    }
    cout << ans << '\n';
}