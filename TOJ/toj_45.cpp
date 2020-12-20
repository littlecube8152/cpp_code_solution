#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count, data;
    vector<int> array;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> data;
        for (int j = 0; j < data; j++)
        {
            int tmp;
            cin >> tmp;
            array.push_back(tmp);
        }
        sort(array.begin(),array.end());
        cout << array.back() - array.front() << '\n';
        array.pop_back();
        array.erase(array.begin());
    }
}