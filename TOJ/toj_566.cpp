#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<int> array(count);
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
    }
    int counting = count, result = counting;
    for (int i = count - 1; i >= 0; i--)
    {
        if (array[i] == counting)
        {
            counting--;
            result--;
        }
    }
    cout << result << '\n';
}