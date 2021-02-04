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
        if (n == 0)
            return 0;
        else if (sqrt(n) - floor(sqrt(n)) < 0.000001)
            cout << "yes\n";
        else
            cout << "no\n";
}