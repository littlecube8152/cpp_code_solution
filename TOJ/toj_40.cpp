#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int a, b, gcd, tb;
    while (cin >> a >> b)
    {
        gcd = a;
        tb = b;
        while (gcd != 0 && b != 0)
        {
            gcd %= b;
            swap(gcd, b);
        }
        cout << (a / gcd) * tb << endl;
    }
}