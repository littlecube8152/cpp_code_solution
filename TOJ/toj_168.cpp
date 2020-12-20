#include <iostream>
using namespace std;
int main()
{
    long long int stick[100005];
    int count;
    while (cin >> count)
    {
        for (int i = count - 1; i >= 0; i--)
        {
            cin >> stick[i];
        }
        int result = 0, height = 0;
        for (int i = 0; i < count; i++)
        {
            if (stick[i] > height)
            {
                result++;
                height = stick[i];
            }
        }
        cout << result << '\n';
    }
}