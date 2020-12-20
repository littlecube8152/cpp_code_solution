#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int a, b, mult;
    while (cin >> a)
    {
        cin >> b;
        mult = a * b;
        while (a != 0 && b != 0)
        {
            a %= b;
            swap(a, b);
        }
        cout << (mult / a) << endl;
    }
}