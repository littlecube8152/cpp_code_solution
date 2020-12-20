#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    char op;
    cin >> a >> op >> b;
    switch ((int)op)
    {
    case 43:
        c = a + b;
        break;
    case 45:
        c = a - b;
        break;
    case 42:
        c = a * b;
        break;
    case 47:
        if (b == 0)
        {
            cout << "ERROR\n";
            return 0;
        }else{
            c = a / b;
        }
        break;
    }
    cout << fixed << setprecision(4) << a << " "<< op << " " << b << " = "  << c << '\n';
    return 0;
}