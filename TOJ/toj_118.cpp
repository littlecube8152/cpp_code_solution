#include <iostream>
using namespace std;

int main()
{
    long long int count, price[1005] = {0};
    cin >> count;
    for (long long int i = 1; i <= count; i++)
    {
        long long int a, b;
        cin >> a >> b;
        price[a] = a * b;
    }
    cin >> count;
    for (long long int i = 1; i <= count; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if (price[a] == b)
        {
            cout << "The shopkeeper is honest.\n";
        }
        else
        {
            cout << b - price[a] << '\n';
        }
    }
}