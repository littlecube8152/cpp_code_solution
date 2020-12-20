#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0);
    int key;
    cin >> key;
    string s;
    while (cin >> s)
    {
        int k = 0;
        for (int i = 0; i < 7; i++)
        {
            if (s[i] == 'X')
            {
                k += pow(2, (6 - i));
            }

        }
        cout << (char)(k ^ key);
    }
}