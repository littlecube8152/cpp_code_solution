#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char c;
    while (cin >> c)
    {
        getline(cin, s);
        s = c + s;
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            int a = (int)s[i];
            int b = (int)s[j];
            if (a <= 64 || a >= 123 || (a <= 96 && a >= 91))
            {
                i++;
            }
            else if (b <= 64 || b >= 123 || (b <= 96 && b >= 91))
            {
                j--;
            }
            else if (a - b == 0 || abs(a - b) == 32)
            {
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        if (i >= j)
        {
            cout << "SETUP! ";
        }
        cout << s << '\n';
    }
}