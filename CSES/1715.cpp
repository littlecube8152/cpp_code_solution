/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, fac[1000005], invfac[1000005], cnt[26], ans = 1;
string s;

ll inv(ll b)
{
    ll p = MOD - 2, a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % MOD;
        p >>= 1;
        b = b * b % MOD;
    }
    return a;
}

signed main()
{
    fast;
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        invfac[i] = inv(fac[i]);
    }
    cin >> s;
    n = s.size();
    for(char c : s)
        cnt[c - 'a']++;
    ans = fac[n];
    for (int i = 0; i < 26; i++)
        ans = (ans * invfac[cnt[i]]) % MOD;
    cout << ans << '\n';
}
