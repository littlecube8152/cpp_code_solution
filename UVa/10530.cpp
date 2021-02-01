#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n, a = 0, b = 11;
    string s;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        cin >> s >> s;

        if (s == "high")
        {
            b = min(b, n);
        }
        if (s == "low")
        {
            a = max(a, n);
        }
        if (s == "on")
        {
            if (n < b && n > a)
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";
            a = 0;
            b = 11;
        }
    }
}