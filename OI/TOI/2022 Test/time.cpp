#pragma GCC optimize("O0")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// using namespace __gnu_pbds;

ll N = 6e8;
ll ans;

signed main()
{
    for (ll i = 1; i <= N; i++)
        ans ^= i;
    cout << ans << '\n';
}
