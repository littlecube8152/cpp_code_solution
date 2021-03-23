#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

map<int, int> mp;

signed main()
{
    fast;
    map<string, string> mp;
    map<string, string> revmp;
    string n, a, b;
    while (cin >> n)
    {
        if (n == "add")
        {
            cin >> a >> b;
            mp[a] = b;
            revmp[b] = a;
        }
        else if (n == "chk")
        {
            cin >> a;
            if (a[0] == 'n')
            {
                a = a.substr(1, a.length() - 1);
                if (mp[a] != "")
                    cout << a << " " << mp[a] << '\n';
                else
                    cout << "Not found.\n";
            }
            else if (a[0] == 'w')
            {
                a = a.substr(1, a.length() - 1);
                if (revmp[a] != "")
                    cout << revmp[a] << " " << a << '\n';
                else
                    cout << "Not found.\n";
            }
        }
        else if (n == "del")
        {
            cin >> a;
            if (a[0] == 'n')
            {
                a = a.substr(1, a.length() - 1);
                revmp[mp[a]] = "";
                mp[a] = "";
            }
            else if (a[0] == 'w')
            {
                a = a.substr(1, a.length() - 1);
                mp[revmp[a]] = "";
                revmp[a] = "";
            }
        }
    }
}