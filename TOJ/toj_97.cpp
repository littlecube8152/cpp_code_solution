#include <iostream>
using namespace std;
int main()
{
    bool a, b;
    cin >> a >> b;
    if (a||b)
    {
        cout << "BUG FREE!" << '\n';
    }
    else
    {
        cout << "BARRIER BREACHED!" << '\n';
    }
}