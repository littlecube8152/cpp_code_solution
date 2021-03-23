#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#pragma pack(1)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

unsigned short n, m, a[1002];

int bs(int L, int R)
{
    if (L == R)
        return L;
    int mid = (L + R) / 2, sum = 0, split = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > mid)
            sum = 0, split++;
        sum += a[i];
        if (a[i] > mid)
            split = 100000;
    }
    if (split <= m)
        return bs(L, mid);
    else
        return bs(mid + 1, R);
}

signed main()
{
    fast;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << bs(0, 1001 * n) << '\n';
    }
}