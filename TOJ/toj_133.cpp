/*********************

As same as TOJ 120

*********************/


#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    long long int count;
    cin >> count;
    long long int tree[200001] = {0};
    for (long long int i = 1; i <= count; i++)
    {
        cin >> tree[i];
        tree[i] += tree[i - 1];
    }
    long long int input;
    cin >> input;
    for (long long int i = 0; i < input; i++)
    {
        long long int result, start, end;
        cin >> start >> end;
        if(start > end){
            swap(start, end);
        }
        result = tree[end] - tree[start - 1];
        cout << result << endl;
    }
}