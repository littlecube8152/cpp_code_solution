#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        string s;
        for (int j = i - 1; j >= 0; j--)
            s = (char)('a' + j) + s;
        for (int j = i - 1; j >= 0; j--)
            cout << s;
        cout << '\n';
    }
}