/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, A[200005], C[200005];
ll ans;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        C[A[i]]++;
    }
    for (ll i = 1; i <= 200000; i++)
        if (C[i])
        {
            ll icnt = C[i];
            for (ll j = i * i; j <= 200000; j += i)
                if (C[j])
                {
                    ll jcnt = C[j];
                    //cout << i << " " << j << " " << j / i << " " << icnt * jcnt * C[j / i] * (j == i * i ? 1 : 2) << '\n';
                    ans += icnt * jcnt * C[j / i] * (j == i * i ? 1 : 2);
                }
        }
    cout << ans << '\n';
}
