#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int list[4];
        cin >> list[0] >> list[1] >> list[2] >> list[3];
        if (list[3] - list[2] == list[2] - list[1] == list[1] - list[0])
        {
            cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << list[3] + list[3] - list[2] << '\n';
        }
        else{
             cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << (int)(list[3] * (double)(list[3] / list[2])) << '\n';
        }
    }
}