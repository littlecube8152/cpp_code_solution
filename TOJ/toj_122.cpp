#include <iostream>
using namespace std;

int main()
{
    long long int a;
    cin >> a;
    if (a < 10)
    {
        cout << "Y\n";
    }
    else if (a < 1000)
    {
        cout << "X\n";
    }
    else if (a < 400000)
    {
        cout << "UV\n";
    }
    else if (a < 700000)
    {
        cout << "VIS\n";
    }
    else if (a < 1000000000)
    {
        cout << "IR\n";
    }
    else
    {
        cout << "R\n";
    }
}