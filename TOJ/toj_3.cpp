#include <iostream>
#include <string>
using namespace std;

int a, b, tmp;
int count;

int main()
{
    cin >> count;
    int result[count];
    for (int i = 0; i < count; i++)
    {
        cin >> a >> b;

        while (b != 0)
        {
            a %= b;
            swap(a, b);
        }

        result[i] = a;
    }
    for (int i = 0; i < count; i++)
    {
        cout << result[i] << endl;
    }
}