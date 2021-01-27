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
    ll n;
    while (cin >> n)
    {
        if (!(n % 400))
            cout << "a leap year\n";
        else if (!(n % 100))
            cout << "a normal year\n";
        else if (!(n % 4))
            cout << "a leap year\n";
        else
        cout << "a normal year\n";
    }
}