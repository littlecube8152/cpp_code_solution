#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<ll> v;

int main()
{
    fast;
    string s;
    cin >> s;
    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5])
    {
        cout << "0";
        return 0;
    }
    if (s[0] + s[1] + s[2] > s[3] + s[4] + s[5])
    {
        int m = s[0] + s[1] + s[2] - (s[3] + s[4] + s[5]);
        s[3] = '9' - s[3] + '0';
        s[4] = '9' - s[4] + '0';
        s[5] = '9' - s[5] + '0';
        sort(&s[0], &s[s.length()], [](int a, int b) { return a > b; });
        for (int i = 0; i < 6; i++)
        {
            m -= s[i] - '0';
            if (m <= 0)
            {
                cout << i + 1;
                return 0;
            }
        }
    }

    if (s[0] + s[1] + s[2] < s[3] + s[4] + s[5])
    {
        int m = (s[3] + s[4] + s[5]) - (s[0] + s[1] + s[2]);
        s[0] = '9' - s[0] + '0';
        s[1] = '9' - s[1] + '0';
        s[2] = '9' - s[2] + '0';
        sort(&s[0], &s[s.length()], [](int a, int b) { return a > b; });
        for (int i = 0; i < 6; i++)
        {
            m -= s[i] - '0';
            if (m <= 0)
            {
                cout << i + 1;
                return 0;
            }
        }
        cout << s;
    }
}