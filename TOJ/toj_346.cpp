#include <iostream>
using namespace std;

int main()
{
    long long int g[100];
    g[0] = 0;
    g[1] = 1;
    for (int i = 2; i <= 95; i++)
    {
        g[i] = g[i - 2] - g[i - 1];
    }
    long long int count;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        int a;
        cin >> a;
        cout << "G(" <<a << ") = "<< g[a] << '\n';
    }
}