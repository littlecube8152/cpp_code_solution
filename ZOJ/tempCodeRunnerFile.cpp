#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll solve(string s)
{
   // cout << "Solving " << s << ":\n";
    if (s[0] == '(' && s[s.length() - 1] == ')')
        return solve(s.substr(2, s.length() - 4));

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            for (; i < s.length(); i++)
                if (s[i] == ')')
                    break;
        if (s[i] == '+')
            return solve(s.substr(0, i - 1)) + solve(s.substr(i + 2, s.length() - i - 2));
        if (s[i] == '-')
            return solve(s.substr(0, i - 1)) + solve(s.substr(i + 2, s.length() - i - 2));
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            for (; i < s.length(); i++)
                if (s[i] == ')')
                    break;
        if (s[i] == '*')
            return solve(s.substr(0, i - 1)) * solve(s.substr(i + 2, s.length() - i - 2));
        if (s[i] == '/')
            return solve(s.substr(0, i - 1)) / solve(s.substr(i + 2, s.length() - i - 2));
        if (s[i] == '%')
            return solve(s.substr(0, i - 1)) % solve(s.substr(i + 2, s.length() - i - 2));
    }

    return stoi(s);
}

int main()
{
    string s;
    while (getline(cin, s))
        cout << solve(s) << '\n';
}