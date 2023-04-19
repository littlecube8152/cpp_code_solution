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
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, A, B, X, Y, Z, ans;

void solve()
{
    cin >> N >> A >> B >> X >> Y >> Z;
    ans = N * X;
    ans = min(ans, (N / A) * Y + (N % A) * X);
    ans = min(ans, (N / B) * Z + (N % B) * X);
    if (A < B)
        swap(A, B), swap(Y, Z);
    if (N / A <= sqrt(N))
        for (int i = 0; i * A <= N; i++)
            ans = min({ans, i * Y + (N - i * A) * X, i * Y + ((N - i * A) / B) * Z + ((N - i * A) % B) * X});
    else
    {
        if (Y * B <= Z * A)
            for (int i = N / A; i >= max(0LL, N / A - (ll)sqrt(N)); i--)
                ans = min({ans, i * Y + (N - i * A) * X, i * Y + ((N - i * A) / B) * Z + ((N - i * A) % B) * X});
        else
            for (int i = 0; i <= min(N / A, (ll)sqrt(N)); i++)
                ans = min({ans, i * Y + (N - i * A) * X, i * Y + ((N - i * A) / B) * Z + ((N - i * A) % B) * X});
    }
    cout << ans << '\n';
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
        solve();
}
