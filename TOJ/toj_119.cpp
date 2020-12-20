#include <iostream>
using namespace std;

int main()
{
    long long int count, query, file[200005] = {0};
    cin >> count;
    for (long long int i = 0; i < count; i++)
    {
        cin >> file[i];
    }
    cin >> query;
    for (long long int i = 0; i < query; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if (abs(a - b) > 8)
        {
            cout << "I QUIT!\n";
            break;
        }
        else
        {
            swap(file[a-1], file[b-1]);
        }
        if (i == query - 1)
        {
            cout << "SORTED!\n";
        }
    }
    for (long long int i = 0; i < count; i++)
    {
        cout << file[i];
        if (i == count - 1)
        {
            cout << '\n';
        }
        else
        {
            cout << " ";
        }
    }
}