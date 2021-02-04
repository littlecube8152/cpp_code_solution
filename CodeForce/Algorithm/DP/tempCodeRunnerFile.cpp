#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, q, d;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> q >> d;
        int qt[11] = {0};
        for (int i = 0; i < 10; i++)
        {
            int j = 1;
            while ((d * j) % 10 != i)
            {
                j++;
            }
            qt[i] = d * j;
        }
        while (q--)
        {
            int temp;
            cin >> temp;
            if (qt[temp % 10] < temp)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}