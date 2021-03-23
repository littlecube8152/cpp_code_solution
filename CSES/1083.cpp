#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int n, ans, x;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        ans += x;
    }
    cout << n * (n + 1) / 2 - ans << '\n';
}
