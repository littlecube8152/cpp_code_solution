#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return max(abs(a), abs(b));
    while (a != 0)
    {
        swap(a, b);
        a %= b;
    }
    return b;
}

int main()
{
    int n, odd = 0, r = 0, g = 0, a[100005] = {0};
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        g = gcd(g, a[i]);

    if (g > 1)
    {
        cout << "YES\n0";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] %= 2;
        if (a[i] == 1)
            odd++;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && a[i + 1] == 0)
        {
            r += 2;
            a[i] = 0;
        }
        else if (a[i] == 1 && a[i + 1] == 1)
        {
            r++;
            a[i] = 0;
            a[i + 1] = 0;
        }
    }
    cout << "YES\n"
         << r;
    // 0 0 | 0 0
    // 0 1 | 1 1
    // 1 0 | 1 1
    // 1 1 | 0 0
}