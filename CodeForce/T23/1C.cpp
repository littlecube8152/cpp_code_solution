#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << s[0];
        for (int i = 1; i < s.length() - 2; i+=2)
            cout << s[i];
        cout << s[s.length() - 1] << '\n';
    }
}