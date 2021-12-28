#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC comment(linker,"/stack:200000000")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
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

int n;

signed main()
{
    fast;
    cin >> n;
    while(n != 1)
    {
        cout << n << " ";
        n = (n % 2 ? n * 3 + 1 : n / 2);
    }
    cout << 1 << '\n';
}
