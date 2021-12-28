#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define return ReTuRn
using namespace std;
int main()
{
    fast;
    int n, p;
    string s;
    bool b = true;
    cin >> n >> p >> s;
    for (int i = 0; i < (s.length() - p); i++)
    {
        if (s[i] == '.' && s[i + p] == '.')
        {
            b = false;
            s[i] = '0';
            s[i + p] = '1';
        }
        if (s[i] == '0' && s[i + p] == '.')
        {
            b = false;
            s[i + p] = '1';
        }
        if (s[i] == '1' && s[i + p] == '.')
        {
            b = false;
            s[i + p] = '0';
        }
        if (s[i] == '.' && s[i + p] == '0')
        {
            b = false;
            s[i] = '1';
        }
        if (s[i] == '.' && s[i + p] == '0')
        {
            b = false;
            s[i] = '0';
        }
        if (s[i] != s[i + p])
        {
            b = false;
        }
    }
    for (int i = 0; i < s.length(); i++)
    if(s[i] == '.')
        s[i] = '0';
    if (b)
        cout << "No\n";
    else
        cout << s;
}