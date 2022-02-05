#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[40], r = 0, o = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] %= 2;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                o++;
            if (i % 2 != a[i] % 2)
                r++;
        }
        if (o == (n + 1) / 2)
            cout << r/2 << '\n';
        else
            cout << "-1\n";
    }
}