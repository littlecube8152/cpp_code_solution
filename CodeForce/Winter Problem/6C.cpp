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
    int n, k;
    cin >> n >> k;
    
    cout << "YES\n";

    if (k > n - 2)
    {
        cout << string(n, '.') << '\n';
        cout << '.' << string(n - 2, '#') << '.' << '\n';
        k -= (n - 2);
        if (k % 2)
            cout << string((n - k) / 2, '.') << string(k, '#') << string((n - k) / 2, '.') << '\n';
        else
            cout << string((n - k - 1) / 2, '.') << string(k / 2, '#') << '.' << string(k / 2, '#') << string((n - k - 1) / 2, '.') << '\n';
        cout << string(n, '.') << '\n';
    }
    else 
    {
        cout << string(n, '.') << '\n';
        if (k % 2)
            cout << string((n - k) / 2, '.') << string(k, '#') << string((n - k) / 2, '.') << '\n';
        else
            cout << string((n - k - 1) / 2, '.') << string(k / 2, '#') << '.' << string(k / 2, '#') << string((n - k - 1) / 2, '.') << '\n';
        cout << string(n, '.') << '\n';
        cout << string(n, '.') << '\n';
    }
}