#include <iostream>
using namespace std;
int main()
{
    int count;
    cin >> count;
    int array[count];
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if(array[j] > array[j+1]){
                swap(array[j], array[j + 1]);
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << '\n';

}