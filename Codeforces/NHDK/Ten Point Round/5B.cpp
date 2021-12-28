#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s;
    int a = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
            a++;
        if (a > 2)
        {
            cout << "Normal Day\n";
            return 0;
        }
    }
    if (a == 2)
        cout << "Lucky Day!\n";
    else
        cout << "Normal Day\n";
}