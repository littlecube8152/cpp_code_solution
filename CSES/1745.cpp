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

int n, x;
bitset<100005> b = 1;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b |= b << x;
    }
    cout << b.count() - 1 << '\n';
    for (int i = 1; i <= 100000;i++)
        if(b[i])
            cout << i << " ";
}