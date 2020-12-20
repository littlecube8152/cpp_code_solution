#include <iostream>
using namespace std;
int main()
{
    int count;
    cin >> count;
    string array[count];
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            int k = 0;
            while(array[j][k] == array[j+1][k]){
                k++;
            }
            if(array[j][k] > array[j+1][k]){
                swap(array[j], array[j + 1]);
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << "\n";
    }

}