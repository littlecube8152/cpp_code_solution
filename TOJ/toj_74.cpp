#include <iostream>

using namespace std;

int main()
{
    string chain;
    cin >> chain;
    for (int i = 1; i <= chain.length(); i++)
    {
        if (chain.length() % i != 0)
        {
            continue;
        }
        bool repeat = true;
        for (int j = 0; j < chain.length() - i; j++)
        {
            if (chain[j] != chain[j + i])
            {
                repeat = false;
                break;
            }
        }
        if (repeat)
        {
            for (int j = 0; j < i; j++)
            {
                cout << chain[j];
            }
            cout << '\n';
            return 0;
        }
    }
}