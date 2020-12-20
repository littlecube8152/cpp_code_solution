#include <iostream>
#include <vector>
using namespace std;
vector<long long int> triangle(100000, 0);

int main()
{
    triangle[0] = 1;
    long long int start, end;
    cin >> start >> end;

    for (long long int i = 1; i < start; i++)
    {
        for (long long int j = i + 1; j >= 1; j--)
        {
            triangle[j] = triangle[j] + triangle[j - 1];
        }
    }
    for (long long int i = start; i < end; i++)
    {
        cout << string(end - i - 1, ' ');
        for (long long int j = i; j >= 1; j--)
        {
            triangle[j] = triangle[j] + triangle[j - 1];
        }
        for (long long int j = 0; j <= i; j++)
        {
            cout << triangle[j] << " ";
        }
        cout << '\n';
    }
}