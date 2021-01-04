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
        int n, r = 0;
        cin >> n;
        while (n > 1)
        {

            if (n % 2 || n == 2)
            {
                n--;
                r++;
            }
            else
            {
                n = 2;
                r++;
            }
        }
        cout << r << '\n';
    }
}