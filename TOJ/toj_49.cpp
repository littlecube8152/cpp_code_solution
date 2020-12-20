#include <iostream>
#include <math.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

void get_data(long long int &a, long long int &b)
{
    char c;
    cin >> c >> a >> c >> b >> c;
}

int main()
{
    string s;
    while (cin >> s)
    {
        long long int a, b;
        get_data(a, b);
        if (s == "GCD")
        {
            cout << gcd(a, b) << '\n';
        }
        else if (s == "LCM")
        {
            cout << a * b / gcd(a, b) << '\n';
        }
        else if (s == "ADD")
        {
            cout << a + b << '\n';
        }
        else if (s == "SUB")
        {
            cout << a - b << '\n';
        }
        else if (s == "MUL")
        {
            cout << a * b << '\n';
        }
        else if (s == "DIV")
        {
            cout << a / b << '\n';
        }
    }
}