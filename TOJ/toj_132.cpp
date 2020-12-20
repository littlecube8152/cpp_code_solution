#include <iostream>
#include <string>
using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    cout << a << endl;
}
