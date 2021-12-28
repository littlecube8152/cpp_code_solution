#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s;
int k;

signed main()
{
    fast;
    cin >> s >> k;
    if (s == "Sunday")
        k = (k + 0) % 7;
    else if (s == "Monday")
        k = (k + 1) % 7;
    else if (s == "Tuesday")
        k = (k + 2) % 7;
    else if (s == "Wednesday")
        k = (k + 3) % 7;
    else if (s == "Thursday")
        k = (k + 4) % 7;
    else if (s == "Friday")
        k = (k + 5) % 7;
    else if (s == "Saturday")
        k = (k + 6) % 7;
    if (k == 0)
        cout << "Sunday";
    if (k == 1)
        cout << "Monday";
    if (k == 2)
        cout << "Tuesday";
    if (k == 3)
        cout << "Wednesday";
    if (k == 4)
        cout << "Thursday";
    if (k == 5)
        cout << "Friday";
    if (k == 6)
        cout << "Saturday";
    cout << '\n';
}