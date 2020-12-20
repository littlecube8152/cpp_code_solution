#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    long long int a, b, c, a_tmp ,power = 2;
    cin >> a >> b >> c;
    a %= c;
    a_tmp = a;
    for (; b > power; )
    {
        a *= a;
        a %= c;
        b -= power;
        power *= 2;
    }
    for (; b > 0; b--)
    {
        a *= a_tmp;
        a %= c;
    }
    cout << a << endl;
}