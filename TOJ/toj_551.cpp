#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll t, n, k;
int main()
{
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> n >> k;
        if (n > 1)
        {
            while (n % 6 == 0)
            {
                n /= 6;
            }
            while (n % 3 == 0 && k > 0)
            {
                n /= 3;
                k--;
            }
        }
        if (n <= 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
