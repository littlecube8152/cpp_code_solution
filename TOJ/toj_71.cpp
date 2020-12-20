#include <iostream>
#include <vector>
using namespace std;
vector<long long int> triangle(1000000, 0);
int main()
{
    long long int m, n;
    cin >> n >> m;
    n--;
    m--;
    if(n - m < m)
        m = n - m;

    triangle[0] = 1;

    for (long long int i = 1; i <= n; i++)
    {
        for (long long int j = m + 1; j >= 1; j--)
        {
            triangle[j] = (triangle[j] + triangle[j - 1]) % 24851;
        }
    }
    cout << triangle[m] << '\n';
}