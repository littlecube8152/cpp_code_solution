#include <iostream>
using namespace std;
long long int screen[2170][1930];
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    long long int height, width, angle;
    cin >> height >> width >> angle;

    for (long long int i = 0; i < height; i++)
    {
        for (long long int j = 0; j < width; j++)
        {
            cin >> screen[i][j];
        }
    }

    switch (angle)
    {
    case 360:
    case 0:
        for (long long int i = 0; i < height; i++)
        {
            for (long long int j = 0; j < width; j++)
            {
                cout << screen[i][j];
                if (j != width - 1){
                    cout << " ";
                }
            }
            cout << '\n';
        }
        break;
    case 90:
        for (long long int i = 0; i < width; i++)
        {
            for (long long int j = 0; j < height; j++)
            {
                cout << screen[height - 1 - j][i];
                if (j != height - 1){
                    cout << " ";
                }
            }
            cout << '\n';
        }
        break;
    case 180:
        for (long long int i = 0; i < height; i++)
        {
            for (long long int j = 0; j < width; j++)
            {
                cout << screen[height - 1 - i][width - 1 - j];
                if (j != width - 1){
                    cout << " ";
                }
            }
            cout << '\n';
        }
        break;
    case 270:
        for (long long int i = 0; i < width; i++)
        {
            for (long long int j = 0; j < height; j++)
            {
                cout << screen[j][width - 1 - i];
                if (j != height - 1){
                    cout << " ";
                }
            }
            cout << '\n';
        }
        break;
    }
    return 0;
}
