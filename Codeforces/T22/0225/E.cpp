#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    for (int i = 1; i < 10000; i++)
    {
        bitset<11> b;
        int ti = i, digit = 0;
        while (ti > 0)
        {
            digit++;
            b[ti % 10] = 1;
            ti /= 10;
        }
        if (b.count() != digit)
            cout << i << " "<< b.count() << '\n';
    }
}