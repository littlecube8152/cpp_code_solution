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
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length();i++)
        cout << (char)(s[i] - 7);
    cout << '\n';
}