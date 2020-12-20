#include <iostream>
using namespace std;
int main()
{
    int a;

    int result = 0;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        int m = 0, n = 0;
        cin >> m >> n;
        m -= n;
        if (m == -2 || m == -3 || m == 5)
        {
            result += 1;
        }
        else if (m == 2 || m == 3 || m == -5)
        {
            result -= 1;
        }
    }
    if (result > 0)
    {
        cout << "The prince wins." << '\n';
    }
    else if (result < 0)
    {
        cout << "The princess wins." << '\n';
    }
    else
    {
        cout << "The referee wins." << '\n';
    }
}