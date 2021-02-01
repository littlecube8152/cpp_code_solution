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
    string a, b, c = "";
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
    int i = 0;

    for (; i < b.length(); i++)
    {
        if (m[b[i]])
        {
            stringstream ss;
            string s;
            for (int j = '0'; j <= '9'; j++)
                if (j == b[i])
                    ss << string(m[j] - 1, (char)(j));
                else
                    ss << string(m[j], (char)(j));
            ss >> s;
            if (s <= b.substr(i + 1, b.length() - i - 1))
            {
                m[b[i]]--;
                c = c + ((char)(b[i]));
                continue;
            }
        }

        for (int j = b[i]; j >= '0'; j--)
        {
            if (m[j])
            {
                m[j]--;
                c = c + ((char)(j ));
                break;
            }
        }
        break;
    }
    cout << c;

    for (int i = 9; i >= 0; i--)
        cout << string(m[i + '0'], (char)(i + '0'));
}