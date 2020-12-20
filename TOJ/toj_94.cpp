#include <iostream>
using namespace std;
int main()
{
    int input = 0;
    cin >> input;
    if (input <= 2 || input >= 12)
    {
        cout << "Winter!\n";
    }
    else if (3 <= input && input <= 5)
    {
        cout << "Spring!\n";
    }
    else if (6 <= input && input <= 8)
    {
        cout << "Summer!\n";
    }
    else
    {
        cout << "Autumn!\n";
    }
}