#include <iostream>
using namespace std;

int main()
{
    int len;
    string str;
    char chr;
    cin >> len >> str >> chr;
    str = "." + str + ".";
    if (chr == 'L')
    {
        cout << str.substr(2, len) << '\n';
    }
    else
    {
        cout << str.substr(0, len)<< '\n';
    }
}