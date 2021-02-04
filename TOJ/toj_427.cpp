#pragma GCC optimize("3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <iostream>
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll phi[1000001] = {0};

signed main()
{

    fast;
    for (int i = 2; i <= 1000000; i += 1)
        phi[i] = i;

    for (int i = 2; i <= 1000000; i += 1)
        if (phi[i] == i)
            for (int j = i; j <= 1000000; j += i)
                phi[j] = phi[j] / i * (i - 1);

    for (int i = 2; i <= 1000000; i += 1)
        phi[i] += phi[i - 1];
    ll n;
    while (cin >> n)
        if (n == 0)
            cout << 0 << '\n';
        else
            cout << phi[n] * 2 + 3 << '\n';
}
