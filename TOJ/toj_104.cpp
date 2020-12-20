#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        cout << string((input - i), ' ');
        cout << string((2 * i - 1), '*');
        cout << endl;
    }
}