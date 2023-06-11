#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int n, a[300005], b[300005] = {0}, q, even = 0, m = 0;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        even = 0;
        m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = 0;
        }
        cin >> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (abs((double)sqrt(a[i] * a[j]) - (int)sqrt(a[i] * a[j])) < 0.00000000000001)
                {
                    b[i]++;
                }
        for (int i = 0; i < n; i++)
        {
            m = max(m, b[i]);
            if (b[i] != 0 && b[i] % 2 == 0)
                even++;
            else if (b[i] == 1 && abs((double)sqrt(a[i]) - (int)sqrt(a[i])) < 0.00000000000001)
                even++;
        }
        while (q--)
        {
            ll w;
            cin >> w;
            if (w == 0)
                cout << m << '\n';
            else
                cout << max(m, even) << '\n';
        }
    }
}
