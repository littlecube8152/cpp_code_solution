#include <iostream>
using namespace std;
int main()
{
    long long int a, b;
    long long int result[100000] = {0};
    result[0] = 1;
    int digit = 1;
    cin >> a >> b;
    if (a > b)
    {
        swap(a, b);
    }
    for (int i = a; i <= b; i++)
    {
        for (int j = 0; j < digit; j++)
        {
            result[j] *= i;
        }
        for (int j = 0; j < digit + 2; j++)
        {
            result[j + 1] += result[j] / 10;
            result[j] %= 10;
        }
        digit++;
        int tmp = i;
        for (; tmp >= 10; digit++)
            tmp /= 10;
        {
        }
        int j = digit;
        for (; j >= 0; j--)
        {
            if (result[j] != 0)
            {
                break;
            }
        }
        digit = j + 1;
    }
    int j = digit - 1;
    for (; j >= 0; j--)
    {
        cout << result[j];
    }
    cout << '\n';
}
