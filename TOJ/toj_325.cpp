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

bitset<1000005> b = 1;
int n, sum, k;

signed main()
{
    cin >> n;
    while (n--)
    {
        cin >> k;
        sum += k;
        b |= b << k;
    }
    for (int i = sum / 2; i >= 0; i--)
        if (b[i])
        {
            cout << i << " " << sum - i << '\n';
            break;
        }
}