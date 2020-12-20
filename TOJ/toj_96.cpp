#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    char op;
    cin >> a >> op >> b;
    switch ((int)op)
    {
    case 43:
        c = a + b;
        cout << a << " + " << b << " = " << c << '\n';
        break;
    case 45:
        c = a - b;
        cout << a << " - " << b << " = " << c << '\n';
        break;
    case 42:
        c = a * b;
        cout << a << " * " << b << " = " << c << '\n';
        break;
    case 47:
        if (b == 0)
        {
            cout << "ERROR\n";
            
        }else{
            c = a / b;
            cout << a << " / " << b << " = " << c << " ... " << a%b << '\n';
        }

        break;
    }
}