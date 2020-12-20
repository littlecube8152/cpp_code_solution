#include <iostream>
using namespace std;
int main()
{
    int count;
    string s;
    int value;
    cin >> count;
    getline(cin, s);
    for (int i = 0; i < count; i++)
    {

        getline(cin, s);
        value = (((int)s[0] - 65) * 676 + ((int)s[1] - 65) * 26 + ((int)s[2] - 65)) - ((((int)s[4] - 48) * 1000) + (((int)s[5] - 48) * 100) + (((int)s[6] - 48) * 10) + (((int)s[7] - 48)));
        if (abs(value) < 100)
        {
            cout << "nice\n";
        }
        else
        {
            cout << "not nice\n";
        }
    }
}