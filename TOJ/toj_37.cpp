#include <iostream>
using namespace std;
int main()
{
    int tmp;

    while (cin >> tmp)
    {
        int result = 1;
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == ' ')
                result++;
        }
        cout << result << '\n';
    }
}