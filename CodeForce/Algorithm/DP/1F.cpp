//
//
//Not Solved Yet
//
//
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
    string a, b;
    map<char, int> m;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        m[a[i]]++;

    if (a.length() < b.length())
    {
        for (int i = 9; i >= 0; i--)
            cout << string(m[i + '0'], (char)(i + '0'));
        return 0;
    }

    for (int i = 0; i < b.length(); i++)
    {
        
    }
}