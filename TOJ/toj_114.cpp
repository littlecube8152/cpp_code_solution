#include <iostream>
using namespace std;

int main()
{
    int screen[7][8] = {{0}};
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            cin >> screen[i][j];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if ((screen[i][j] == screen[i + 1][j] && screen[i + 1][j] == screen[i + 2][j]) || (screen[i][j] == screen[i][j + 1] && screen[i][j + 1] == screen[i][j + 2]))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}