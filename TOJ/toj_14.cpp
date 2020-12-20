#include <iostream>
#include <math.h>
using namespace std;

//This program using 4-digit per Array
//const int MAX = 10000;

int main()
{
    long long int a[100000] = {0};
    long long int b[100000] = {0};
    long long int result[100000] = {0};
    string op;
    char tmp;
    int digit_counter = 0;
    result[0] = 1;
    cin >> op;

    //Send in numbers
    int i = 0;
    while (cin >> tmp)
    {
        if (tmp == ' ')
        {
            break;
        }
        a[i] += tmp * pow(10, digit_counter);
        digit_counter++;
        if (digit_counter >= 4)
        {
            i++;
            digit_counter = 0;
        }
    }
    digit_counter = 0;
    i = 0;
    while (cin >> tmp)
    {
        if (tmp == '\n')
        {
            break;
        }
        b[i] += tmp * pow(10, digit_counter);
        digit_counter++;
        if (digit_counter >= 4)
        {
            i++;
            digit_counter = 0;
        }
    }
    if (op == "mul")
    {
    }
    else if (op == "pow")
    {
    }

    //int j = 100000;
    for (int j = 100000; j >= 0; j--)
    {
        if (a[j] != 0)
        {
            cout << a[j];
        }
    }
    cout << " ";
    for (int j = 100000; j >= 0; j--)
    {
        if (b[j] != 0)
        {
            cout << b[j];
        }
    }
}
