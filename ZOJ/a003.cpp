#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a = (a * 2 + b) % 3;
    if (a == 0)
    {
        cout << "普通\n";
    }
    else if (a == 1)
    {
        cout << "吉\n";
    }
    else
    {
        cout << "大吉\n";
    }
}