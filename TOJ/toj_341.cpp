#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (long long int i = 1; i <= count; i++)
    {
        double a, b, c, d, tmp,bc, answer;
        cin >> a >> b >> c >> d;
        bc = (c / 3 / a - b * b / 9 / a / a);
        tmp = (b * c / 6 / a / a) - (b * b * b / 27 / a / a / a) - (d / 2 / a);
        answer = -1 * b / 3 / a + cbrt(tmp + sqrt(tmp * tmp + bc*bc*bc))+ cbrt(tmp - sqrt(tmp * tmp + bc*bc*bc));
        printf("%.3f\n", answer);
    }
}

