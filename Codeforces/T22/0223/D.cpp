#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;
ll n, a, b;

int main()
{
    cin >> n >> a >> b;
    if ((n == 2 || n ==  3) && a * b == 1)
    {
        cout << "NO";
        return 0;
    }
    if (a == 1 && b == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << (abs(i - j) == 1 ? "1" : "0");
                 cout << '\n';
        }
    }
    else if (a == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << (((i < b) || (j < b)) && i != j ? "1" : "0");
            cout << '\n';
        }
    }
    else if (b == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << (((i < a) || (j < a)) || i == j ? "0" : "1");
            cout << '\n';
        }
    }
    else
        cout << "NO";
}