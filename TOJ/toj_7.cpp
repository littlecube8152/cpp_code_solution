#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;
    int output[input];
    for (int i = 0; i < input; i++)
    {
        int count;
        cin >> count;
        int speed[count+1];
        for (int j = 0; j < count+1; j++)
        {
            cin >> speed[j];
        }
        for (int j = 0; j < (count); j++)
        {
            for (int k = 0; k < (count); k++)
            {
                speed[k] = - speed[k] + speed[k + 1];
            }
            speed[count - j] = 0;
        }
        output[i] = speed[0];
    }
    for (int i = 0; i < input; i++)
    {
        cout << output[i] << "\n";
    }
}