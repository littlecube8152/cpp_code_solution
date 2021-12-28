#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 2147483647 / 2
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
string s;
stringstream ss;
ll n;
signed main()
{
    fast;

    while (getline(cin, s))
    {

        ss << s;
        ll n, sum = 0;
        while (ss >> n)
            sum += n;
        cout << sum << '\n';
    }
}