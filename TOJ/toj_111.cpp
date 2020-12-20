#include <iostream>
using namespace std;

int main()
{
    int x, y, pwd = 2;
    cin >> x >> y;
    while (pwd % x != 0)
    {
        pwd = pwd * 2 + 1;
    }
    if (pwd % y == 0)
    {
        cout << "right\n";
    }
    else
    {
        cout << "left\n";
    }
}