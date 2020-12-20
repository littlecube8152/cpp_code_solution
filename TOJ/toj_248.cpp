#include <iostream>
using namespace std;

int main()
{
    long long int a, b;
    cin >> a >> b;

    for (long long int i = 1; i <= a; i++)
    {
        for (long long int j = 1; j <= b; j++)
        {
            long long int k = i * j;
            cout << i << "*" << j << "=" << k << " ";
        }
        cout << '\n';
    }
}
