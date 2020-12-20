#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d, p, q;
    char op;
    cin >> a >> b >> op >> c >> d;
    switch (op)
    {
    case '+':
        p = a + c;
        q = b + d;
        break;
    case '-':
        p = a - c;
        q = b - d;
        break;
    case '*':
        p = a * c - b * d;
        q = a * d + b * c;
        break;
    case '/':
        p = (a * c + b * d) / (c * c + d * d);
        q = (b * c - a * d) / (c * c + d * d);
        break;
    }
    if (q > 0)
    {
        cout << setprecision(2) << fixed << p << "+" << q << "i\n";
    }
    else
    {
        cout << setprecision(2) << fixed << p << q << "i\n";
    }
}