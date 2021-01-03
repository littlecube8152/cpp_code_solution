#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

ll n, r;
bool b[300005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp, r = 0;
        cin >> tmp;
        while (tmp != 0)
        {
            r += tmp % 2;
            tmp /= 2;
        }
        b[i] = r % 2;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll c = b[i];
        for (int j = i + 1; j < n; j++)
        {
            c = c ^ b[j];
            if (c == 0)
                r++;
        }
    }
    cout << r << '\n';
}