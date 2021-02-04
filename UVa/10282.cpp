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
    map<string, string> m;
    string s, t;

    while (getline(cin, s))
    {
        if (s == "")
            break;
        stringstream ss;
        ss << s;
        ss >> s >> t;
        m[t] = s;
    }

    while (cin >> s)
    {
        if (s == "")
            break;
        if (m[s] == "")
            cout << "eh\n";
        else
            cout << m[s] << '\n';
    }
}