#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

ll total = 0, target, a[200000], weak[200000], tests;
int main()
{
    cin >> tests >> target;
    for (int i = 0; i < tests; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < tests; i++)
    {
        int b;
        cin >> b;
        weak[i] = b - a[i];
        total += b;
    }
    sort(weak, weak + tests);
    for (int i = 0; i < tests; i++)
    {
        if (total - weak[i] >= target)
        {
            total -= weak[i];
        }
        else
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << tests << '\n';
}