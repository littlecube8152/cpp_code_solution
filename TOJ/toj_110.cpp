#include <iostream>
using namespace std;
int main()
{
    int input;
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        int h;
        cin >> h;
        for (int j = 1; j <= h-3; j++)
        {
            cout << string(h - j, ' ') << string(2 * j - 1, '*') << '\n';
        }
        cout << string(2 * h - 1, '*') << '\n';
        cout << " " << string(2 * h - 3, '*') << '\n';
        cout << string(2 * h - 1, '*') << '\n';
        for (int j = h-3; j >=1; j--)
        {
            cout << string(h - j, ' ') << string(2 * j - 1, '*') << '\n';
        }
    }
}