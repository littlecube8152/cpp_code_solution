#include <iostream>
using namespace std;

int main()
{
    long long int length, windows[2][100000];
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        char chr;
        cin >> chr;
        windows[0][i] = ((int)chr - 48);
    }
    for (int i = 0; i < length; i++)
    {
        char chr;
        cin >> chr;
        windows[1][i] = ((int)chr - 48);
    }
    for (int i = 0; i < length; i++)
    {
        if (windows[0][i] == 0 &&
            windows[1][i] == 0)
        {
            cout << "FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
        if (windows[0][i] == 1 && windows[0][i + 1] == 0 &&
            windows[1][i] == 0 && windows[1][i + 1] == 1)
        {
            cout << "FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
        if (windows[0][i] == 0 && windows[0][i + 1] == 1 &&
            windows[1][i] == 1 && windows[1][i + 1] == 0)
        {
            cout << "FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
    }
    cout << "FENDED OFF!\n";
}