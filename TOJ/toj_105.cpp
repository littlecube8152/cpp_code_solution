#include <iostream>
using namespace std;

int main()
{
    long output = 2;
    for (int i = 1; i <= 25; i++)
    {
        output *= 2;
        output += 1;
    }
    cout << output << endl;
}