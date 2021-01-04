#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll n, m;
    map<ll, ll> p;
    cin >> n >> m;
    n -= 2000;
    while (m--)
    {
        int d;
        cin >> d;
        p[d]++;
    }
    for (int i = 1; i <= n; i++)
        if (p[i] % 2 == 0)
            cout << string(n - i, ' ') << string(2 * i - 1, '*') << '\n';
        else
        {
            cout << string(n - i, ' ');
            for (int j = 0; j < i; j++)
            {
                cout << (char)(j + 65);
            }
            for (int j = i - 2; j >= 0; j--)
            {
                cout << (char)(j + 65);
            }
            cout << '\n';
        }
    for (int i = 1; i < n; i++)
        cout << ' ' << string(2 * n - 3, '^') << '\n';
}