#include <iostream>
using namespace std;

int main()
{
    int floor, square;
    cin >> floor >> square;
    char chr = '*';
    for (int i = 1; i <= floor; i++)
    {
        for (int j = 1; j <= square; j++)
        {
            if (i % 2 == 1)
            {
                chr = '*';
            }
            else
            {
                chr = ' ';
            }
            for (int k = 1; k <= floor; k++)
            {
                cout << string(square, chr);
                if (chr == '*')
                {
                    chr = ' ';
                }
                else
                {
                    chr = '*';
                }
            }
            cout << '\n';
        }
    }
}