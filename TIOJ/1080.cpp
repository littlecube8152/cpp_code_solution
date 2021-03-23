#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[1000005], b[1000005], bit[1000005], result = 0, c = 0;

signed main()
{
    fast;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        c++;
        map<int, int> m;
        result = 0;
        for (int i = 1; i <= n; i++)
            bit[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            b[i] = a[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++)
            m[b[i]] = i;
        for (int i = 1; i <= n; i++)
            a[i] = m[a[i]];

        for (int i = 1; i <= n; i++)
        {
            for (int j = a[i]; j > 0; j -= (j & -j))
                result += bit[j];
            for (int j = a[i]; j <= n; j += (j & -j))
                bit[j]++;
        }
        cout << "Case #" << c << ": ";
        cout << n*(n-1)/2 - result << '\n';
    }
}