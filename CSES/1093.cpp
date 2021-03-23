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

ll n, cnt[126000];

signed main()
{
    cin >> n;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int bound = i * (i - 1) / 2;
        for (int j = bound; j >= 0; j--)
            cnt[j + i] = (cnt[j + i] + cnt[j]) % MOD;
    }
    if (n * (n + 1) % 4)
        cout << 0;
    else
        cout << cnt[n * (n + 1) / 4] * (MOD - MOD / 2) % MOD << '\n';
}