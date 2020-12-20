#include <iostream>
using namespace std;
int main()
{
    for (int i = 1;; i++)
    {
        int count;
        cin >> count;
        if (count == 0)
        {
            break;
        }
        int year[20][3];
        for (int j = 0; j < count; j++)
        {
            int y, a, b;
            cin >> y >> a >> b;
            year[j][0] = y;
            year[j][1] = b - a;
            year[j][2] = 0;
        }
        for (int j = 0; j < count - 1; j++)
        {
            while (year[j][0] != year[j + 1][0] && year[j][0] < 10000 && year[j][0] < 10000)
            {
                if (year[j][0] < year[j + 1][0])
                {
                    year[j][0] += year[j][1];
                }
                else if (year[j][0] > year[j + 1][0])
                {
                    year[j + 1][0] += year[j + 1][1];
                }
                if (year[j][0] == year[j + 1][0])
                {
                    year[j][2] = 1;
                    year[j + 1][2] = 1;
                }
            }
        }
        cout << "Case #" << i << ":\n";
        if (year[count - 1][2] == 1)
        {
            cout << "The actual year is " << year[count - 1][0] << ".\n\n";
        }
        else
        {
            cout << "Unknown bugs detected.\n\n";
        }
    }
}