#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s;
ll ind = 0;

map<string, int> solve()
{
    map<string, int> m;
    for (; ind < s.length();)
    {
        if (s[ind] == ')')
        {
            ind++;
            return m;
        }
        else if (s[ind] == '(')
        {
            ind++;
            map<string, int> subm = solve();
            string multi = "";
            int mul = 1;
            while ('0' <= s[ind] && s[ind] <= '9')
            {
                multi = multi + s[ind];
                ind++;
            }
            if (multi != "")
                mul = stoi(multi);
            for (auto i : subm)
                m[i.first] += i.second * mul;
        }
        else if('A' <= s[ind] && s[ind] <= 'Z')
        {
            string element = s.substr(ind, 1);
            ind++;
            if ('a' <= s[ind] && s[ind] <= 'z')
            {
                element = element + s[ind];
                ind++;
            }
            string multi = "";
            int mul = 1;
            while ('0' <= s[ind] && s[ind] <= '9')
            {
                multi = multi + s[ind];
                ind++;
            }
            if (multi != "")
                mul = stoi(multi);
            m[element] += mul;
        }
        else
            ind++;
    }
    return m;
}

signed main()
{
    cin >> s;
    cout << s << '\n';
    s = s + "        ";
    map<string, int> M = solve();
    for(auto i:M)
        cout << i.first << ":" << i.second << '\n';
}