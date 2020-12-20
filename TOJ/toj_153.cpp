#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int index;
    cin >> index;
    for (int i = 1; i <= index; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c)
        {
            cout << "illegal triangle\n";
            continue;
        }
        int x = a * a + b * b - c * c;
        if (x < 0)
        {
            cout << "acute triangle\n";
        }
        if (x == 0)
        {
            cout << "right triangle\n";
        }
        if (x > 0)
        {
            cout << "obtuse triangle\n";
        }
    }
}