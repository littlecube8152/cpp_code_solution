#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[1000005];

signed main()
{
    fast;
    int n, k, m;
    while (cin >> n >> k)
    {
        for (int i = 0; i < 1000005; i++)
            a[i] = 0;
        while (n--)
        {
            cin >> m;
            a[m]++;
        }
        int sum = 0;
        for (int i = 1000004; i >= 0; i--)
        {
            sum += a[i];
            if(sum >= k)
            {
                cout << i << '\n';
                break;
            }
        }
    }
}