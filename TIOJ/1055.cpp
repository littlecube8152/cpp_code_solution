#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
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

int a, b;

signed main()
{
    fast;
    cin >> a >> b;
    for (int i = a; i != b; i += (b - a) / abs(a - b))
        cout << string(i, '*') << '\n';
    cout << string(b, '*') << '\n';
}